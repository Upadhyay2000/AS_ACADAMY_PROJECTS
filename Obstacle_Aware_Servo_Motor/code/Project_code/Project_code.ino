#include <Servo.h>

Servo myServo;
int pirPin = 2;       // PIR sensor output pin
int servoPin = 9;     // Servo motor control pin
int pirValue = 0;     // Variable to store PIR status

void setup() {
  pinMode(pirPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0);   // Initial position
  Serial.begin(9600);
}

void loop() {
  pirValue = digitalRead(pirPin);
  
  if (pirValue == HIGH) {
    Serial.println("Motion Detected : ");
    myServo.write(90);    // Rotate to 90°
    delay(500);          // Wait for 1 sec
  } else {
    Serial.println("No Motion");
    myServo.write(0);     // Return to 0°
  }

  delay(50); // Short delay to avoid flickering
}

