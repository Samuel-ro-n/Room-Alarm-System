#include "LCD.h"

LCD::LCD(uint8_t address, uint8_t columns, uint8_t rows, int sdaPin, int sclPin)
  : lcd(0x27, 16, 2) {
  this->sdaPin = 14;
  this->sclPin = 15;
}

void LCD::begin(){
  Wire.setSDA(sdaPin);
  Wire.setSCL(sclPin);
  Wire.begin();

  lcd.init();
  lcd.backlight();
  //showStartupMessage();
  //showPrompt();
}

void LCD::showStartupMessage(){
  lcd.setCursor(1, 0);
  lcd.print("Welcome Samuel!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1 User Login");
  lcd.setCursor(0, 1);
  lcd.print("2 New Password");
}

void LCD::showPrompt(){
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Enter Password:");
}

void LCD::showGranted() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Access Granted");
}

void LCD::showDenied(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Access Denied");
}

void LCD::clear(){ 
  lcd.clear(); 
  }

void LCD::setCursor(uint8_t col, uint8_t row){
   lcd.setCursor(col, row); 
   }

void LCD::print(const String &s){
   lcd.print(s); 
   }

void LCD::print(char c){
   lcd.print(c); 
   }
