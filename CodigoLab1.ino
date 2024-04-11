// C++ code
//
#include <Servo.h>

int VarSensor = 0;

int FotoResistencia = 0;

Servo servo_12;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  servo_12.attach(12, 500, 2500);
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  servo_12.write(0);
}

void loop()
{
  VarSensor = 0.01723 * readUltrasonicDistance(10, 11);
  FotoResistencia = analogRead(A0);
  if (FotoResistencia > 1000 && VarSensor >= 80) {
    servo_12.write(180);
    digitalWrite(13, HIGH);
  } else {
    if (FotoResistencia < 1000 && VarSensor <= 30) {
      servo_12.write(60);
      digitalWrite(13, LOW);
    }
  }
  if (FotoResistencia < 200 && VarSensor == 2) {
    servo_12.write(90);
  }
  delay(10); // Delay a little bit to improve simulation performance
}