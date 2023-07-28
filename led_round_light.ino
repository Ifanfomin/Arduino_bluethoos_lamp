#define LED_PIN 13
#define NUM_LEDS 8
#include "FastLED.h"
CRGB leds[NUM_LEDS];
int led_num = 0;
int value = 255;
int len = 5; // длина крутящегося элемента
int value_change = 0;

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  pinMode(13, OUTPUT); // 6 вольт, 0,03 А
  if (len == 0) {
    value_change = value;
  } else {
    value_change = value / len;
  }
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++){
    led_num = i;
    value = 255;
    leds[led_num] = CHSV(127, 255, 255);
    FastLED.show();
    delay(80);
    for (int j = 0; j < len; j++) {
      if (led_num == -1) {
        led_num = 7;
      }
      leds[led_num--] = CHSV(127, 255, value = value - value_change);
    }
  }
}
