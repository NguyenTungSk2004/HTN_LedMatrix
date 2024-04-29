#include <Arduino.h>
#include <cambien.h>

CamBien nhietdo, doam;

void setup() {
  pinMode(ST_CP,OUTPUT);//RCLK
  
  pinMode(DS_E,OUTPUT);//SER E
  pinMode(SH_CP_E,OUTPUT);//SRCLK E

  pinMode(SH_CP_A,OUTPUT);//SRCLK A
  pinMode(DS_A,OUTPUT);//SER A
}

void loop() {
  // nhietdo.ReadTemperature();
  // nhietdo.ReadTemperatureInternet();
  // doam.ReadHumidity();
  // ToData("12") --> chuyển đổi hexa 
  // ShowScreen();
  if(button == 1)
      ShowScreenRightToLeft(nhietdo.data());
  else
      ShowScreenLeftToRight(doam.data());
}



