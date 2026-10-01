#include "Buzzer.h"

Buzzer::Buzzer(int pin){
  this->Buzzer1 = PB4;
  pinMode(Buzzer1, OUTPUT);
}

void Buzzer::correct(){
  tone(Buzzer1, 150, 250);
}

void Buzzer::wrong(){
  tone(Buzzer1, 263, 250);
}