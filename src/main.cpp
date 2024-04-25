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
  nhietdo.ReadTemperature();
  doam.ReadTemperature();
  
  // ShowScreen("Nhiet do");
  ShowScreen(nhietdo.data());
  // ShowScreen(" ");
  //ShowScreen("Do am ")
  ShowScreen(doam.data());
}



