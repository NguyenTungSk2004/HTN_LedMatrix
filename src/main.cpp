#include <Arduino.h>
#include <Screen.h>
#include <DataProcess.h>
#include <Screen.h>

void buttonManualClicked() {
  boardWipe();
  mode++;
}

void setup() {
    dht.begin();
    pinMode(ST_CP, OUTPUT);  // RCLK

    pinMode(DS_hang, OUTPUT);     // SER row
    pinMode(SH_CP_hang, OUTPUT);  // SRCLK row

    pinMode(SH_CP_cot, OUTPUT);  // SRCLK column
    pinMode(DS_cot, OUTPUT);     // SER column

    pinMode(buttonManual, INPUT_PULLUP);
    pinMode(buttonOnline, INPUT_PULLUP);

    attachInterrupt(buttonManual, buttonManualClicked, RISING);
}
void loop() {
  currentMode = mode;
  String text = "H:" + ReadHumidity() + "% T:" + ReadTemperature() + "c";
  // các chế độ hiển thị
   switch (mode) {
    case 0:
      //Hiển thị chế độ auto
      hienthia(text,20,30);
      hienthib(text,10,30);
      break;
    case 1:
      // Hiển thị kịch bản 1
      hienthia(text,10,30);
      break;
    case 2:
      // Hiển thị kịch bản 2
      hienthib(text,10,30);
      break;
    default:
      mode = 0;
      break;
  }
}

