#ifndef DataProcess_h
#define DataProcess_h

#include <vector>
#include <data.h>

using namespace std;

//Hàm truyền bit vào ic 74hc595 - LSB
void truyenbit(int DS , int SH_CP , int number){
    digitalWrite(ST_CP,LOW);
    shiftOut(DS , SH_CP , LSBFIRST , number); 
    digitalWrite(ST_CP,HIGH);
}

// Trả về index trong mảng indexChu ở file data.h
int GetIndex(int d){
    return 0;
}


/*
    Hàm thực hiện trả về một mảng các bit để hiển thị 
    ví dụ: 
        array = {
            {0xFF,0xC1,0x80,0xB6,0xB6,0x90,0xD9,0xFF},
            {0xFF,0x9F,0x9F,0xB8,0xA0,0x87,0x9F,0xFF},
            {0xFF,0xC9,0x80,0xB6,0xB6,0x80,0xC9,0xFF}
        };
*/
vector<vector<byte>> renderArraysBit(int data) {
    vector<vector<byte>> arrays;
    while(data !=0){
        int d = data%10;
        int index = GetIndex(d);

        vector<byte> z = chu[index];
        arrays.push_back(z);
        
        data = data/10;
    }
    return arrays;
}


/*
    Xử lí dữ liệu internet
*/
void InternetConnection(){

}


#endif