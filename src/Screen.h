#ifndef Screen_h
#define Screen_h

#include <DataProcess.h>
/*
    Module Hiển thị
*/

void ShowScreen(String myString){
    int *result; 
    result = renderIndex_chu(myString); // trả ra một mảng index 

    // Hiển thị dữ liệu đã chuyển đổi
    for(int i = 0; i < myString.length(); i++) {
        int index = result[i];  
        for (int j = 0; j < 8; j++) {
            truyenbit(DS_A, SH_CP_A, chu[index][j]);
            truyenbit(DS_E, SH_CP_E, E >> j);
        }
        delay(2);

    }

    delete[] result;
}

void ShowScreenRightToLeft(String myString){

}
void ShowScreenLeftToRight(String myString){

}

#endif
