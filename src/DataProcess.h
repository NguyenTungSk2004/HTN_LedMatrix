#ifndef DataProcess_h
#define DataProcess_h

#include <DHT.h>
#include <string.h>
#include <data.h>


#define DHTPIN 0     // Chân kết nối với cảm biến DHT11
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

using namespace std;

//Hàm truyền bit vào ic 74hc595 - LSB
void truyenbit(int DS , int SH_CP , int number){
    digitalWrite(ST_CP,LOW);
    shiftOut(DS , SH_CP , LSBFIRST , number); 
    digitalWrite(ST_CP,HIGH);
}

int GetIndex(char c){
    for(size_t i = 0; i < strlen(characters); i++){
        if(c == characters[i]) return i;
    }
    return 0;
}

int* renderIndex_chu(String data) {
    int *arrays = new int[data.length()]; // Dynamically allocate an array
    for(size_t i = 0; i < data.length(); i++) {
        arrays[i] = GetIndex(data[i]);
    }
    return arrays;
}

/*
    Module cảm biến
*/
// Phương thức đọc dữ liệu độ ẩm
int ReadHumidity(){
    float humidity = dht.readHumidity();
    if(!isnan(humidity)){
        return (int)humidity;
    }
    return 0;
}
//Phương thức đọc dữ liệu nhiệt độ
int ReadTemperature(){
    float temperature = dht.readTemperature();
    if(!isnan(temperature)){
        return (int)temperature;
    } 
    return 0;
}

#endif