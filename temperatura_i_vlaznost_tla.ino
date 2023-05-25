#include <LiquidCrystal.h>
#include "DHT.h"

# define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

int sensorPin = A0;
int outputValue ;
//DHT DHT1;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  lcd.begin(16, 2);
  lcd.print("Citanje podataka sa senzora ...");
  dht.begin();
  delay(2000);
}

void loop()
{
  outputValue= analogRead(sensorPin);
  outputValue = map(outputValue,550,0,0,100);
  
  lcd.setCursor(0,0);
  lcd.print("Vlaznost tla: ");
  lcd.print(outputValue);
  lcd.print("%");
  delay(5000);
  lcd.clear();
  float t=dht.readTemperature();
  float h=dht.readHumidity();
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Greska pri citanju!"));
    return;
  }
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);

  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Vlaz. zraka:");
  lcd.print(h);
  lcd.print("%");
  delay(5000);
  lcd.clear();
  
}