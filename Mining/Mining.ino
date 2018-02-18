// shape 1: 0-44
// shape 2: 45-90
// shape 3- 91-118
// Shape 4 119-200

#include <Adafruit_NeoPixel.h>
#define PIN            6
#define NUMPIXELS      200
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  Serial.begin(9600);
  strip.begin();
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
}
void loop() {
  if (!digitalRead(10)) {
    Serial.println("1");
    setSection(91, 117 , 0, random(100, 255), random(0, 255));

    setSection(45, 90 , random(0, 255), random(0, 255), 0);
  }
  if (!digitalRead(11)) {
    Serial.println("2");
    setSection(0, 44 , random(0, 255), 0, random(0, 255));
    setSection(118, 200 , random(100, 255), random(0, 255), random(0, 255));
  }

}
void setSection(int start, int finish, int red, int green, int blue) {
  for (int i = start; i < finish; i++)
  {
    strip.setPixelColor(i, red, green, blue);
  }
  strip.show();
}
