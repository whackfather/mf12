// Linear Potentiometer Test Code
// Written by Roman Rodrigez

// Include statements
#include <Arduino.h>

// Global constants
const float a = 2.4f;
const float b = 3.01f;
const float c = 7.08f;
const float sigma = 1.720894f;

// Function declarations
float length(int, float);
float suspensionLength(float);

// Setup
void setup() {
  Serial.begin(9600);
}

// MAIN LOOP
void loop() {
  float rawVal = analogRead(A0); // Change pin value to reflect testing environment
  float potLen = length(3, rawVal);
  float susLen = suspensionLength(potLen);
  Serial.println(susLen);
  delay(100);
}

// Returns length of a given potentiometer in inches
float length(int wheel, float rawVal) {
  switch(wheel) {
    case 1: // Front Left Pot
      return (((79.0f / 1018.0f) * rawVal) - (79.0f / 1018.0f)) / 25.4;
    case 2: // Front Right Pot
      return (((78.81f / 1020.0f) * rawVal) - (78.81f / 1020.0f)) / 25.4;
    case 3: // Rear Left Pot
      return ((((-76.0f / 1023.0f) * rawVal) + 76) + 223) / 25.4;
    case 4: // Rear Right Pot
      return ((((-76.0f / 1023.0f) * rawVal) + 76) + 223) / 25.4;  // Same equations as rear pot 1, hopefully its fine
  }

  return -1;
}

// Gets length of suspension given length of potentiometer
float suspensionLength(float p) {
  float aSqrd = a * a;
  float bSqrd = b * b;
  float cSqrd = c * c;
  float pSqrd = p * p;
  float phi = acos((cSqrd - pSqrd - aSqrd) / (-2 * p * a));
  float theta = sigma - phi;

  float susLenSqrd = pSqrd + bSqrd - (2 * p * b * cos(theta));

  return sqrt(susLenSqrd);
}