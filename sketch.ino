#include "KeypadReader.h"
#include "LCD.h"
#include "Servomotor.h"
#include "Buzzer.h"

KeypadReader key;
Buzzer Buzz(PB4);
LCD display( 0x27, 16, 2, 14, 15);
Servomotor servo(2);

String systemCode="";

void Logon(){
  display.showStartupMessage();
  char option= key.getKey();
  while (option == 0) { 
    option = key.getKey();
  }
  switch(option){
    case '1':{
      display.showPrompt();
      String entered= inputCode();
      if (systemCode == "") {
        display.clear();
        display.print("No code set yet");
          delay(2000);
          display.clear();
          break;
        }
      if (entered == systemCode) {
        display.clear();
        display.showGranted();
        servo.Unlock();
        Buzz.correct();
        delay(3000);
        display.clear();
        servo.Lock();
      } 
      else {
          display.clear();
          display.showDenied();
          Buzz.wrong();
          delay(2000);
          display.clear();
        }
        break;
    }
    case '2':
      SetNewCode();
      break;
    default:
      break;
  }
}

//Function to Input Code on Second Row
String inputCode(){
  display.setCursor(5, 1);
  display.print("[____]");
  display.setCursor(6, 1);
  String password = "";
  while (password.length() < 4) {
    char passkey = key.getKey();
    if (passkey >= '0' && passkey <= '9') {
      display.print('*');
      password += passkey;
    }
  }
  return password;
}

//Function for Setting New Code
bool SetNewCode(){
  display.clear();
  display.setCursor(0, 0);
  display.print("Enter New Password:");
  display.setCursor(6, 1);
  String NewCode= inputCode();
  while(true){
    display.clear();
    display.setCursor(0, 0);
    display.print("Confrim New Password:");
    display.setCursor(6, 1);
    String ConfirmCode= inputCode();
    if (NewCode==ConfirmCode){
      systemCode = NewCode;
      display.clear();
      return true;
    }
    else{
      display.clear();
      display.setCursor(3, 0);
      display.print("Try Again");
      display.setCursor(1, 1);
      display.print("Code No Match");
      delay(1000);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.println("Hello, STM32!");
  servo.begin();
  display.begin();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Logon();
  delay(10);
}
