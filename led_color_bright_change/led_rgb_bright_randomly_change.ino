#define LED_PIN 13
#define NUM_LEDS 8
#include "FastLED.h"
CRGB leds[NUM_LEDS];
int led_num = 0;
int leds_ch[8][5]; // [мин_яркость, макс_яркость, изменение яркости(1-растёт, 0-гаснет), зелёный, красный]

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS); //.setCorrection( TypicalLEDStrip )
  FastLED.setBrightness(50);
  pinMode(13, OUTPUT); // 6 вольт, 0,03 А
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_ch[i][0] = random(10, 40);
    leds_ch[i][1] = random(50, 102);
    leds_ch[i][2] = 1;
  }
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    led_num = i;
    leds[led_num] = CRGB(leds_ch[led_num][4], leds_ch[led_num][3], 0);
    if (leds_ch[led_num][0] == leds_ch[led_num][3]) {
      leds_ch[led_num][1] = random(50, 102);
      leds_ch[led_num][2] = 1;
    }
    if (leds_ch[led_num][1] == leds_ch[led_num][3]) {
      leds_ch[led_num][0] = random(10, 40);
      leds_ch[led_num][2] = 0;
    } 
    if (leds_ch[led_num][2] == 1) {
      leds_ch[led_num][3]++;
      if (leds_ch[led_num][4] % 2 == 0) {
        leds_ch[led_num][4] = leds_ch[led_num][4] + 2;
      } else {
        leds_ch[led_num][4] = leds_ch[led_num][4] + 3;
      }
    } else {
      leds_ch[led_num][3]--;
      if (leds_ch[led_num][4] % 2 == 0) {
        leds_ch[led_num][4] = leds_ch[led_num][4] - 2;
      } else {
        leds_ch[led_num][4] = leds_ch[led_num][4] - 3;
      }
    }
  }
