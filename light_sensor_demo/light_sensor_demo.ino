#include <Adafruit_NeoPixel.h>

#define TRIG_PIN 6
#define ECHO_PIN 7
#define LED_PIN 4
#define MIN_DIST 2
#define MAX_DIST 20

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, LED_PIN, NEO_RGB + NEO_KHZ800);
// defines variables
long duration;
int distance;
int greenVal = 255;
int redVal = 0;


void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input  

  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor

  if ( distance <= MAX_DIST) {
    Serial.print("Distance: "); 
    Serial.print(distance);
    int color = (255 *  (distance -2)) / MAX_DIST;
    Serial.print(" RED: ");
    Serial.println(color);
    greenVal = color;
    redVal = 255 - color;
    
  } else {
    greenVal = 255;
    redVal = 0;
  }
  
  strip.setPixelColor(0, greenVal,  redVal, 0);
  strip.show();

  
}
