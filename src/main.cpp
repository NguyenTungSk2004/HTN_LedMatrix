#include <Arduino.h>
#include <cambien.h>

CamBien nhietdo, doam;

void setup() {
  pinMode(ST_CP,OUTPUT);//RCLK
  
  pinMode(DS_E,OUTPUT);//SER E
  pinMode(SH_CP_E,OUTPUT);//SRCLK E

  pinMode(SH_CP_A,OUTPUT);//SRCLK A
  pinMode(DS_A,OUTPUT);//SER A

  pinMode(buttonManual,INPUT_PULLUP); //button manual with pull-up res in arduino
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


void loop() {
  buttonManualClicked();
}



