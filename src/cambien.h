#ifndef cambien_h
#define cambien_h

#include <Arduino.h>
#include <DHT.h>
#include <functions.h>

#define DHTPIN 0     // Chân kết nối với cảm biến DHT11
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

class CamBien{
    protected:
        int data;
    public: 
        CamBien(){
            data = -1;
        }
        // Phương thức đọc dữ liệu độ ẩm
        void ReadHumidity(){
            float humidity = dht.readHumidity();
            if(!isnan(humidity)){
                this.data = (int)humidity;
            } 
        }
        //Phương thức đọc dữ liệu nhiệt độ
        void ReadTemperature(){
            float temperature = dht.readTemperature();
            if(!isnan(temperature)){
                this.data = (int)temperature;
            } 
        }
        //Trả ra dữ liệu 
        vector<vector<byte>> getData(){
            return renderArraysBit(this.data);   
        }
};

#endif