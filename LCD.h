#ifndef LCD_H
#define LCD_H
#define I2C_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_LINES   2

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

class LCD{
  private:
    LiquidCrystal_I2C lcd;
    int sdaPin;
    int sclPin;
  public:
    LCD(uint8_t address, uint8_t columns, uint8_t rows, int sdaPin, int sclPin);
    void begin();
    void showPrompt();
    void showGranted();
    void showStartupMessage();
    void showDenied();
    void setCursor(uint8_t col, uint8_t row);
    void print(const String &s);
    void print(char c);
    void clear();
};

#endif