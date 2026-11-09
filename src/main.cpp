#include <Arduino.h>

const int LED_PIN = 2;
const int CS_PIN_OUT = 25;
const int CS_PIN_IN = 26;

String input = "OFF";


void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Hello World");
  pinMode(LED_PIN, OUTPUT);
  pinMode(CS_PIN_OUT, OUTPUT);
  pinMode(CS_PIN_IN, INPUT_PULLDOWN);  
}

void loop() {
  digitalWrite(LED_PIN, digitalRead(CS_PIN_IN));

  if (Serial.available()){
    input = Serial.readStringUntil('\n');
    input.trim(); //get rid of special characters
  }

  if (input == "ON") {
    digitalWrite(CS_PIN_OUT, HIGH);
  }
  else {
    digitalWrite(CS_PIN_OUT, LOW);
  }
}

