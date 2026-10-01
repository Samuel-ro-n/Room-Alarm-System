#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H
#include <Arduino.h>
#include <Servo.h>

class Servomotor{
private:
  int servo1;
  Servo servoMotor;
public:
  Servomotor(int pin);
  void begin();
  void Unlock();
  void Lock();
};
#endif
