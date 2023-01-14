#include <Servo.h>
// Declare the Servo pin
int servoPin = 3;
// Create a servo object
Servo Servo1;
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration1, duration2;
int distance1, distance2;
void setup() {
  Servo1.attach(servoPin);
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  Serial.begin(9600);        // Starts the serial communication
}
void loop() {
  int gets = measureSpeed();
  if (gets > 100) {
    bumpUp();
  } else {
    bumpDown();
  }
}

void bumpUp() {
  Servo1.write(90);
}

void bumpDown() {
  Servo1.write(0);
}

int measureSpeed() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2;
  delay(1000);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance2 = duration2 * 0.034 / 2;

  int speed = abs(distance1 - distance2);
  // Prints the distance on the Serial Monitor
  Serial.print("sped: ");
  Serial.println(speed);
  return speed;
}
