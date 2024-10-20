// Brakelight
// MF12
// Written by Roman Rodriguez

// Includes and defines
#include <Arduino.h>
#include "Adafruit_NeoPixel.h"
#define LED_PIN 2
#define LED_COUNT 18
#define CTX_PIN 4
#define CRX_PIN 5
#define FUN_PIN 3

// Declare strip object
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Function declarations
bool braking();
void rainbow();

// Setup
void setup() {
  strip.begin();
  strip.show();
  pinMode(FUN_PIN, INPUT);
}

// Loop
void loop() {
  if (braking()) {
    for (int i = 0; i <= LED_COUNT; i++) {
      strip.setPixelColor(i, 255, 0, 0);
    }
  } 
  else if (digitalRead(FUN_PIN)) {
    rainbow();
  } 
  else {
    for (int i = 0; i <= LED_COUNT; i++) {
      strip.setPixelColor(i, 0, 0, 0);
    }
  }
  strip.show();
}

// Function definitions
bool braking() {
  // Do some CAN line reading to check if we is braking or not
  return false;
}

void rainbow() {
  // Make the lights do a rainbow (wave style? synchronized?)
}