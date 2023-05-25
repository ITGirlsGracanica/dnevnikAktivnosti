
const int BUTTON_PIN1 = 7; // Arduino pin connected to button's pin
const int RELAY_PIN1  = 3; // Arduino pin connected to relay's pin
const int BUTTON_PIN2 = 6; // Arduino pin connected to button's pin
const int RELAY_PIN2  = 2; // Arduino pin connected to relay's pin

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN1, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(RELAY_PIN1, OUTPUT);        // set arduino pin to output mode
  pinMode(BUTTON_PIN2, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(RELAY_PIN2, OUTPUT);        // set arduino pin to output mode
}

void loop() {
  int buttonState1 = digitalRead(BUTTON_PIN1); // read new state
  int buttonState2 = digitalRead(BUTTON_PIN2); // read new state

  if (buttonState1 == HIGH) {
    Serial.println("The button is being pressed");
    digitalWrite(RELAY_PIN1, HIGH); // turn on
  }
  else
  if (buttonState1 == LOW) {
    Serial.println("The button is unpressed");
    digitalWrite(RELAY_PIN1, LOW);  // turn off
  }
  if (buttonState2 == HIGH) {
    Serial.println("The button is being pressed");
    digitalWrite(RELAY_PIN2, HIGH); // turn on
  }
  else
  if (buttonState2 == LOW) {
    Serial.println("The button is unpressed");
    digitalWrite(RELAY_PIN2, LOW);  // turn off
  }
}