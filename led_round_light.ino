#define LED_PIN 13
#define NUM_LEDS 8
#include "FastLED.h"
CRGB leds[NUM_LEDS];
int led_num = 0;

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS); //.setCorrection( TypicalLEDStrip )
  FastLED.setBrightness(50);
  pinMode(13, OUTPUT); // 6 вольт, 0,03 А
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++){
    led_num = i;
    leds[led_num] = CHSV(127, 255, 255);
    FastLED.show();
    delay(100);
    leds[led_num--] = CHSV(127, 255, 0);
  }
}
