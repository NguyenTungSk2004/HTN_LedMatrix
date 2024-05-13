#ifndef DataProcess_h
#define DataProcess_h

#include <DHT.h>
#include <DHT_U.h>
#include <string.h>
#include <data.h>


#define DHTPIN 2     // Chân kết nối với cảm biến DHT11
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

using namespace std;
/*
    Module cảm biến
*/
// Phương thức đọc dữ liệu độ ẩm
String ReadHumidity(){
    int humidity = (int)dht.readHumidity();
    if(!isnan(humidity)){
        return (String)humidity;
    }
}
//Phương thức đọc dữ liệu nhiệt độ
String ReadTemperature(){
    int temperature = (int)dht.readTemperature();
    if(!isnan(temperature)){
        return (String)temperature;
    } 
}

/*
    Module Internet
*/

#endif