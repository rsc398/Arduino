#include <Adafruit_NeoPixel.h>
 
#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
#define PIN2 7
Adafruit_NeoPixel strip2=Adafruit_NeoPixel(60,PIN2,NEO_GRB+NEO_KHZ800); 
void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
 
void loop() {
  strip.setPixelColor(0,strip.Color(255,0,0));
  strip.show();
} 
