#ifndef data_h
#define data_h

#include "Arduino.h"

#define DS_A 12
#define SH_CP_A 13

#define DS_E 9
#define SH_CP_E 10

#define ST_CP 11

#define buttonManual 4
#define buttonOnline 3


int E = 0b10000000; // Dữ liệu cực dương -> quét cột bằng: E >> i(1-8)
int chu[][8] = { 
  {0xFF,0xC0,0x80,0xB7,0xB7,0x80,0xC0,0xFF}, //A
  {0xFF,0x80,0x80,0xB6,0xB6,0x80,0xC9,0xFF}, //B
  {0xFF,0xC1,0x80,0xBE,0xBE,0x9C,0xDD,0xFF}, //C
  {0xFF,0x80,0x80,0xBE,0xBE,0x80,0xC1,0xFF}, //D
  {0xFF,0x80,0x80,0xB6,0xB6,0xBE,0xBE,0xFF},//E
  {0xFF,0x80,0x80,0xB7,0xB7,0xBF,0xBF,0xFF},//F
  {0xFF,0xC1,0x80,0xBE,0xBA,0x98,0xD9,0xFF},//G
  {0xFF,0x80,0x80,0xF7,0xF7,0x80,0x80,0xFF},//H
  {0xFF,0xFF,0xBE,0x80,0x80,0xBE,0xFF,0xFF},//I
  {0xFF,0xF9,0xF8,0xBE,0x80,0x81,0xBF,0xFF},//J
  {0xFF,0x80,0x80,0xE3,0xC9,0x9C,0xBE,0xFF},//K
  {0xFF,0x80,0x80,0xFE,0xFE,0xFE,0xFE,0xFF},//L
  {0xFF,0x80,0x80,0xCF,0xE7,0xCF,0x80,0x80},//M
  {0xFF,0x80,0x80,0xCF,0xE7,0xF3,0x80,0x80},//N
  {0xFF,0xC1,0x80,0xBE,0xBE,0x80,0xC1,0xFF},//O
  {0xFF,0x80,0x80,0xBB,0xBB,0x83,0xC7,0xFF},//P
  {0xFF,0xC3,0x81,0xBD,0xBD,0x80,0xC2,0xFF},//Q
  {0xFF,0x80,0x80,0xB3,0xB1,0x84,0xCE,0xFF},//R
  {0xFF,0xCD,0x84,0xB6,0xB6,0x90,0xD9,0xFF},//S
  {0xFF,0x9F,0xBF,0x80,0x80,0xBF,0x9F,0xFF},//T
  {0xFF,0x81,0x80,0xFE,0xFE,0x80,0x80,0xFF},//U
  {0xFF,0x83,0x81,0xFC,0xFC,0x81,0x83,0xFF},//V
  {0xFF,0x80,0x80,0xF9,0xF3,0xF9,0x80,0x80},//W
  {0xFF,0x9C,0x88,0xE3,0xF7,0xE3,0x88,0x9C},//X
  {0xFF,0x8F,0x87,0xF0,0xF0,0x87,0x8F,0xFF},//Y
  {0xFF,0xBC,0xB8,0xB2,0xA6,0x8E,0x9E,0xFF},//Z
  {0xFF,0xFE,0xEE,0x80,0x80,0xFE,0xFE,0xFF},//1
  {0xFF,0xDC,0x98,0xBA,0xB6,0x86,0xCE,0xFF},//2
  {0xFF,0xDD,0x9C,0xB6,0xB6,0x80,0xC9,0xFF},//3
  {0xFF,0xF3,0xEB,0xDB,0x80,0x80,0xFB,0xFF},//4
  {0xFF,0x8D,0x8C,0xAE,0xAE,0xA0,0xB1,0xFF},//5
  {0xFF,0xC1,0x80,0xB6,0xB6,0x90,0xD9,0xFF},//6
  {0xFF,0x9F,0x9F,0xB8,0xA0,0x87,0x9F,0xFF},//7
  {0xFF,0xC9,0x80,0xB6,0xB6,0x80,0xC9,0xFF},//8
  {0xFF,0xCD,0x84,0xB6,0xB6,0x80,0xC1,0xFF},//9
  {0xFF,0xC1,0x80,0xAE,0xB6,0x80,0xC1,0xFF},//0
  {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}//space

};

// mảng chứa các characters thực có index tương ứng ở mảng byte bên trên
char characters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ' '};


// Biến của xử lí buttonManualClicked();
volatile boolean pressed = false;
volatile int ModeState = 0;
unsigned long lastDebounceTime = millis();
unsigned long debounceDelay = 20; 
#endif