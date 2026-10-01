#ifndef BUZZER_H
#define BUZZER_H
#include <Arduino.h>

class Buzzer{
private:
  int Buzzer1;
public:
  Buzzer(int pin);
  void correct();
  void wrong();
};
#endif