#define LED_PIN 13
#define NUM_LEDS 8
#include "FastLED.h"
CRGB leds[NUM_LEDS];
byte counter;

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS); //.setCorrection( TypicalLEDStrip )
  FastLED.setBrightness(50);
  pinMode(13, OUTPUT); // 6 вольт, 0,3 А
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++){   //от 0 до трети
    leds[i] = CHSV(counter + i * 20, 255, 255); //HSV. Увеличиваем HUE (цвет)
    // умножение i уменьшает шаг радуги
  }
  counter++;  // меняется от 0 до 255 т.к. байт
  FastLED.show();
  delay(5);  // время ожидания (скорость движения радуги)
}
