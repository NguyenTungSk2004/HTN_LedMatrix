#include <Arduino.h>
// #include <DHT.h>
// #include <Adafruit_Sensor.h>
#include <stdio.h>
#include "nutbam.h"
#include "cambien.h"
// #include "hienthi.h"

// #define DHTPIN 2       // Chân dữ liệu của DHT11 kết nối với chân 2 của Arduino
// #define DHTTYPE DHT11  // Loại cảm biến (DHT11 hoặc DHT22)

// DHT dht(DHTPIN, DHTTYPE);

void setup() {
    // Khởi động cảm biến DHT11
  // dht.begin();
}

void loop() {

  // Đọc dữ liệu nhiệt độ và độ ẩm từ cảm biến
  // float humidity = dht.readHumidity();
  // float temperature = dht.readTemperature();

  // Nhận vào data nhiệt độ, độ ẩm
  // nhietdo = cambien.NhietDo() -> return một giá int
  // doam = cambien.DoAm() -> return một giá trị int
  // hienthi(nhietdo)
}

int main(){
  printf("%d",hello());
}
