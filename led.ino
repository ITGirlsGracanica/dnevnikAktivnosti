#include <IRremote.h>  

const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define ven1 8
#define ven2 13
#define pump 7
#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define led6 9
#define led7 10
#define led8 12

boolean ven1_est;
boolean ven2_est;
boolean pump_est;
boolean led1_est;
boolean led2_est;
boolean led3_est;
boolean led4_est;
boolean led5_est;
boolean led6_est;
boolean led7_est;
boolean led8_est;

void setup() {
  Serial.begin(9600);
  pinMode(ven1,OUTPUT);
  pinMode(ven2,OUTPUT);
  pinMode(pump,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);
  ven1_est=false;
  ven2_est=false;
  pump_est=false;
  led1_est=false;
  led2_est=false;
  led3_est=false;
  led4_est=false;
  led5_est=false;
  led6_est=false;
  led7_est=false;
  led8_est=false;
  irrecv.enableIRIn(); 
}

void loop() {
  // put your main code here, to run repeatedly:
 
 if (irrecv.decode(&results)){
 Serial.println(results.value, HEX);
 irrecv.resume();
 
 if (results.value == 0xFF30CF) ven1_est = !ven1_est;
 if (results.value == 0xFF42BD) ven2_est = !ven2_est;
 if (results.value == 0xFF5AA5) pump_est = !pump_est;
 if (results.value == 0xFF18E7) led1_est = !led1_est;
 if (results.value == 0xFF7A85) led2_est = !led2_est;
 if (results.value == 0xFF10EF) led3_est = !led3_est;
 if (results.value == 0xFF38C7) led4_est = !led4_est;
 if (results.value == 0xFF4AB5) led5_est = !led5_est;
 if (results.value == 0xFF52AD) led6_est = !led6_est;
 if (results.value == 0xFF6897) led7_est = !led7_est;
 if (results.value == 0xFFE01F) led8_est = !led8_est;
 }
 if(ven1_est){
 Serial.println(ven1_est);
 digitalWrite(ven1,HIGH);
 //digitalWrite(led1,led1_est);
 
}
else{
  digitalWrite(ven1,LOW);
}
if(ven2_est){
 Serial.println(ven2_est);
 digitalWrite(ven2,HIGH);
}
else{
  digitalWrite(ven1,LOW);
}
if(pump_est){
 Serial.println(pump_est);
 digitalWrite(pump,HIGH);
 delay(5000);
 //digitalWrite(pump,LOW);
 pump_est=false;
 
}
else{
  digitalWrite(pump,LOW);
}
if(led1_est){
 Serial.println(led1_est);
 digitalWrite(led1,HIGH);
 //digitalWrite(led1,led1_est);
 
}
else{
  digitalWrite(led1,LOW);
}
if(led2_est){
 Serial.println(led2_est);
 digitalWrite(led2,HIGH);
}
else{
  digitalWrite(led2,LOW);
}
if(led3_est){
 Serial.println(led3_est);
 digitalWrite(led3,HIGH);
 //digitalWrite(led1,led1_est);
 
}
else{
  digitalWrite(led3,LOW);
}
if(led4_est){
 Serial.println(led4_est);
 digitalWrite(led4,HIGH);
 //digitalWrite(led1,led1_est);
 
}
else{
  digitalWrite(led4,LOW);
}
if(led5_est){
 Serial.println(led5_est);
 digitalWrite(led5,HIGH);
}
else{
  digitalWrite(led5,LOW);
}
if(led6_est){
 Serial.println(led6_est);
 digitalWrite(led6,HIGH);
}
else{
  digitalWrite(led6,LOW);
}
if(led7_est){
 Serial.println(led7_est);
 digitalWrite(led7,HIGH);
}
else{
  digitalWrite(led7,LOW);
}
if(led8_est){
 Serial.println(led8_est);
 digitalWrite(led8,HIGH);
}
else{
  digitalWrite(led8,LOW);
}
}