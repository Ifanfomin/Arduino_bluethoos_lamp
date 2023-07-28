#define LED_PIN 13
#define NUM_LEDS 8
#include "FastLED.h"
CRGB leds[NUM_LEDS];
int led_num = 0;
int leds_ch[8][8]; // [мин_яркость, макс_яркость, изменение яркости(1-растёт, 0-гаснет), яркость, мин_цвет, макс_цвет, изменение цвета(0-увеличивается, 1-уменьшается), цвет]
int min_br[2] = {100, 120}; // пределы минимальной яркости
int max_br[2] = {150, 255}; // пределы максимальной яркости
int min_hue[2] = {130, 150}; // пределы минимального цвета по Hue
int max_hue[2] = {151, 170}; // пределы максимального цвета по Hue

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  pinMode(13, OUTPUT); // 6 вольт, 0,03 А
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_ch[i][0] = random(min_br[0], min_br[1]);
    leds_ch[i][1] = random(max_br[0], max_br[1]);
    leds_ch[i][2] = 1;
    leds_ch[i][3] = random(min_br[0], min_br[1]);
    leds_ch[i][4] = random(min_hue[0], min_hue[1]);
    leds_ch[i][5] = random(max_hue[0], max_hue[1]);
    leds_ch[i][6] = 1;
    leds_ch[i][7] = 0;
  }
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    led_num = i;
    leds[led_num] = CHSV(leds_ch[led_num][7], 255, leds_ch[led_num][3]);

    //меняем яркость
    if (leds_ch[led_num][3] == leds_ch[led_num][0]) {
      leds_ch[led_num][1] = random(max_br[0], max_br[1]);
      leds_ch[led_num][2] = 1;
    }
    if (leds_ch[led_num][3] == leds_ch[led_num][1]) {
      leds_ch[led_num][0] = random(min_br[0], min_br[1]);
      leds_ch[led_num][2] = 0;
    }
    
    if (leds_ch[led_num][2] == 1) {
      leds_ch[led_num][3]++;
    } else {
      leds_ch[led_num][3]--;
    }

    // меняем цвет
    if (leds_ch[led_num][7] == leds_ch[led_num][4]) {
      leds_ch[led_num][5] = random(max_hue[0], max_hue[1]);
      leds_ch[led_num][6] = 1;
    }
    if (leds_ch[led_num][7] == leds_ch[led_num][5]) {
      leds_ch[i][4] = random(min_hue[0], min_hue[1]);
      leds_ch[led_num][6] = 0;
    }
    if (leds_ch[led_num][6] == 1) {
      leds_ch[led_num][7]++;
    } else {
      leds_ch[led_num][7]--;
    }
  }
  FastLED.show();
  delay(10);
}
