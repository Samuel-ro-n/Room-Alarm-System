#ifndef KEYPAD_READER_H
#define KEYPAD_READER_H

#define KEYPAD_ROWS 4
#define KEYPAD_COLS 3

#include <Arduino.h>
#include <Keypad.h>  

class KeypadReader{
  private:
    byte rowPins[KEYPAD_ROWS] = {PC7, PA7, PA6, PA5};
    byte colPins[KEYPAD_COLS] = {A0, A1, A2};
    char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
      {'1', '2', '3'},
      {'4', '5', '6'},
      {'7', '8', '9'},
      {'*', '0', '#'}
    };
    Keypad keypad;
  public:
    KeypadReader();
    char getKey();
};
#endif