#include <RobotKit.h>

#define TRIG_PIN 13
#define ECHO_PIN 2
#define MIN_DIST 2
#define MAX_DIST 10

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  
  // Robotkit Setup
  setMotors();

  // Proximity sensor setup
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input  

  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
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

  Serial.println(distance);

  if ( distance <= MAX_DIST) {
    int rNumber = random(10);
    if ( rNumber <= 4){
      pivotLeft(100,200);
    } else {
      pivotRight(100,200);
    }
    backward(100,50);
    delay(300);
  }
  stopMotors();
}
