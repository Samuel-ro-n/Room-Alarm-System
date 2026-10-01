#include "KeypadReader.h"

KeypadReader::KeypadReader():keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS){}

char KeypadReader::getKey(){
  char k= keypad.getKey();
  if (k == 'NO_KEY'){
    return 0;
  }
  return k;
}