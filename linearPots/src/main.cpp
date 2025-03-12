#include <Arduino.h>

float compression(int, float);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float rawVal = analogRead(A0); // Change pin value to reflect testing environment
  float compMm = compression(3, rawVal);
  Serial.println(compMm);
  delay(100);
}

float compression(int wheel, float rawVal) {
  switch(wheel) {
    case 1: // Front pot 1
      return ((79.0f / 1018.0f) * rawVal) - (79.0f / 1018.0f);
    case 2: // Front pot 2
      return ((78.81f / 1020.0f) * rawVal) - (78.81f / 1020.0f);
    case 3: // Rear pot 1
      return ((-76.0f / 1023.0f) * rawVal) + 76;
  }
}
