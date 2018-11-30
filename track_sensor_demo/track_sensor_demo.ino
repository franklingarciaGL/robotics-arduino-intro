#define TRACK_S1 2
#define TRACK_S2 3

#define TRIG_PIN 7
#define ECHO_PIN 4


long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(TRACK_S1, INPUT);
  pinMode(TRACK_S2, INPUT);

  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input  
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valS1 = digitalRead(TRACK_S1);
  int valS2 = digitalRead(TRACK_S2);

  Serial.print("S1: ");
  if (valS1 == HIGH) {
    Serial.println("HIGH");
  } else {
    Serial.println("LOW");    
  }

  Serial.print("S2: ");
  if (valS2 == HIGH) {
    Serial.println("HIGH");
  } else {
    Serial.println("LOW");    
  }

  // Distance 

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
  Serial.print("Distance: ");
  Serial.println(distance);

  
  delay(2000);
  

}
