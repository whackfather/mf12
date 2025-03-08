#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  float potValue = analogRead(A0); // Change pin value to reflect testing environment
  Serial.println(potValue);
  delay(100);
}