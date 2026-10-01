#include "Servomotor.h"

Servomotor::Servomotor(int pin) {
  this->servo1 = 2;
}

void Servomotor::begin() {
  servoMotor.attach(servo1);
  servoMotor.write(90);   // Servomotored position
}

void Servomotor::Unlock() {
  servoMotor.write(0);  // unServomotored position
}

void Servomotor::Lock() {
  servoMotor.write(90);   // back to Servomotored position
}