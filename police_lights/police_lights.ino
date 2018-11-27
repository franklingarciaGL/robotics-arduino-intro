#include <Adafruit_NeoPixel.h>

#define LED_PIN 4
#define DELAY 50
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, LED_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  light(255,0);
  light(255,0);
  light(255,0);
  delay(100);
  light(0,255);
  light(0,255);
  light(0,255);
}

void light(int red, int blue){
  strip.setPixelColor(0, 0,  red, blue);
  strip.show();
  delay(DELAY);

  strip.setPixelColor(0, 0,  0, 0);
  strip.show();
  delay(DELAY);

}

