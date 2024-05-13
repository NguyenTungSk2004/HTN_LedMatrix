#ifndef Screen_h
#define Screen_h

#include <DataProcess.h>
/*
    Module Hiển thị
*/
void ShowScreen_1_Led(int index){
    int tocdo = 50;
    int led[][8]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    //Đẩy bit kí tự
    for(int h=0;h<8;h++)
    {
        for(int j=0;j<7;j++)
        {
            led[0][j]=led[0][j+1];
        }
        led[0][7]=chu[index][h];
        for(int w=0;w<tocdo;w++)
        {
            for(int i=0;i < 8;i++)
            {
                truyenbit(DS_Hang,SH_CP_Hang,led[0][i]);
                truyenbit(DS_Cot,SH_CP_Cot, cot >> i);
            }  
        }
    }

}

void ShowScreen(String myString){
    int *result; 
    result = renderIndex_chu(myString); // trả ra một mảng index 
    for(int i = 0; i < myString.length(); i++){
        int index = result[i];
        ShowScreen_1_Led(index);
    }
    
    delete[] result;
}



#endif
