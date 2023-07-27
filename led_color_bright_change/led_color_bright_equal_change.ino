#define LED_PIN 13
#define NUM_LEDS 8
#include "FastLED.h"
CRGB leds[NUM_LEDS];
int led_num = 0;
byte green = 0;
bool green_key = true;
byte red = 0;

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS); //.setCorrection( TypicalLEDStrip )
  FastLED.setBrightness(50);
  pinMode(13, OUTPUT); // 6 вольт, 0,03 А
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    led_num = i;
    leds[led_num] = CRGB(red, green, 0);
  }
  if (green == 102) {
    green_key = false;
  }
  if (green == 20) {
    green_key = true;
  }
  if (green_key == true) {
    green++;
    if (red % 2 == 0) {
      red = red + 2;
    } else {
      red = red + 3;
    }
  } else {
    green--;
    if (red % 2 == 0) {
      red = red - 2;
    } else {
      red = red - 3;
    }
  }
  FastLED.show();
  delay(10);
}
