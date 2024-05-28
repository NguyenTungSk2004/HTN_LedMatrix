#include <Arduino.h>
#include <Screen.h>
#include <DataProcess.h>


#include <Screen.h>

void buttonOnlineClicked(){
  Serial.println("Online");
}

void buttonManualClicked() {
  Serial.println("Manual");
  boardWipe();
  mode++;
}

void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(ST_CP, OUTPUT);  // RCLK
    pinMode(7,OUTPUT); //
    pinMode(DS_hang, OUTPUT);     // SER row
    pinMode(SH_CP_hang, OUTPUT);  // SRCLK row

    pinMode(SH_CP_cot, OUTPUT);  // SRCLK column
    pinMode(DS_cot, OUTPUT);     // SER column

    pinMode(buttonManual, INPUT);
    pinMode(buttonOnline, INPUT);

    attachInterrupt(0, buttonManualClicked, RISING);
    attachInterrupt(1, buttonOnlineClicked, RISING);
}
void loop() {
  currentMode = mode;
  String text = "H:" + ReadHumidity() + "% T:" + ReadTemperature() + "c";
  Serial.println(text);
  // các chế độ hiển thị
   switch (mode) {
    case 0:
      //Hiển thị chế độ auto
      hienthia(text,20,10);
      boardWipe();
      hienthib(text,20,10);
      boardWipe();
      break;
    case 1:
      // Hiển thị kịch bản 1
      hienthia(text,20,10);
      break;
    case 2:
      // Hiển thị kịch bản 2
      hienthib(text,20,10);
      break;
    default:
      mode = 0;
      break;
  }
}

