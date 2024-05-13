#include <Arduino.h>
#include <Screen.h>
#include <DataProcess.h>

void setup() {
  pinMode(ST_CP,OUTPUT);//RCLK
  
  pinMode(DS_Hang,OUTPUT);//SER A,B,C,D
  pinMode(SH_CP_Hang,OUTPUT);//SRCLK A,B,C,D

  pinMode(SH_CP_Cot,OUTPUT);//SRCLK E
  pinMode(DS_Cot,OUTPUT);//SER E

  pinMode(buttonManual,INPUT_PULLUP); //button manual with pull-up res in arduino
}

void loop() {
  ShowScreen("BA");
}


void buttonManualClicked() {
  //Xử lí nhiễu và click (nhấn rồi thả ra == 1 click)
  if (millis() - lastDebounceTime > debounceDelay) {
    int currentState = digitalRead(buttonManual);
    
    if (currentState == LOW && pressed == false) {
      pressed = true;
    } 
   
    if (currentState == HIGH && pressed == true) {
      ModeState++; 
      pressed = false; 
    }
    lastDebounceTime = millis();
  }
  
  // các chế độ hiển thị
   switch (ModeState) {
    case 0:
      //Hiển thị chế độ auto
      break;
    case 1:
      // Hiển thị kịch bản 1
      break;
    case 2:
      // Hiển thị kịch bản 2
      break;
    default:
      ModeState = 0;
      break;
  }
}