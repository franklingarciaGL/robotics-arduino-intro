#include <Servo.h>

#define TRIG_PIN 6
#define ECHO_PIN 7
//#define LED_PIN 4 
#define SERVO_PIN 8
#define MIN_DIST 2
#define MAX_DIST 20
#define DELAY 10

long duration;
int distance;
boolean sweep;

Servo servo;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input  

  servo.attach(SERVO_PIN);
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

  if (distance < 5){
    sweep = true;
  } else {
    sweep = false;
    servo.write(0);
  }

  if (sweep){
      servo.write(0);
      delay(DELAY);
      servo.write(180);
      delay(DELAY);
  }
}
