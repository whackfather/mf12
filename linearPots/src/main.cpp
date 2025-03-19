#define _USE_MATH_DEFINES
#include <Arduino.h>
#include <cmath>

// Adjust the following values to match real world
const float sigma = 85 * (M_PI / 180);
const float a = 10, b = 10, c = 20;

float length(int, float);

float compression(int, float);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float rawVal = analogRead(A0); // Change pin value to reflect testing environment
  float potLen = length(3, rawVal);
  float potSqrd = potLen * potLen;
  
  float phi = acos(((c * c) - potSqrd - (a * a)) / (-2 * potLen * a));
  float theta = sigma - phi;
  float susSqrd = potSqrd + (b * b) - (2 * potLen * b * cos(theta));
  float susLen = sqrt(susSqrd);

  Serial.println(susLen);

  delay(100);
}

float length(int wheel, float rawVal) {
  switch(wheel) {
    case 1: // Front pot 1
      return ((79.0f / 1018.0f) * rawVal) - (79.0f / 1018.0f);
    case 2: // Front pot 2
      return ((78.81f / 1020.0f) * rawVal) - (78.81f / 1020.0f);
    case 3: // Rear pot 1
      return ((-76.0f / 1023.0f) * rawVal) + 76;
  }
}
