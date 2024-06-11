#include <Arduino.h>

// Define pins
const int trigPin = 23;
const int echoPin = 19;
const int ledPin = 21;

// Define the maximum distance to detect an obstacle
const int maxDistance = 10; // in centimeters

void setup() {
  // Configure pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor
  int duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  // Calculate LED brightness based on distance
  int brightness = map(distance, 0, maxDistance, 255, 0); // Map distance to PWM range
  brightness = constrain(brightness, 0, 255); // Ensure brightness is within PWM range
  analogWrite(ledPin, brightness); // Set LED brightness using PWM
}