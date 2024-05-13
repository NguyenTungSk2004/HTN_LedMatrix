#include <DHT_U.h>

#define DS_cot 9 // DATA
#define DS_hang 12

#define SH_CP_hang 13 //CLOCK 
#define SH_CP_cot 10

#define ST_CP 11 // LATCH

#include <DHT.h>  // thu vien ben ngoai

DHT dht(8, DHT11);

byte chu[][8] = {
  { 0xFF, 0xC0, 0x80, 0xB7, 0xB7, 0x80, 0xC0, 0xFF },  //A
  { 0xFF, 0x80, 0x80, 0xB6, 0xB6, 0x80, 0xC9, 0xFF },  //B
  { 0xFF, 0xC1, 0x80, 0xBE, 0xBE, 0x9C, 0xDD, 0xFF },  //C
  { 0xFF, 0x80, 0x80, 0xBE, 0xBE, 0x80, 0xC1, 0xFF },  //D
  { 0xFF, 0x80, 0x80, 0xB6, 0xB6, 0xBE, 0xBE, 0xFF },  //E
  { 0xFF, 0x80, 0x80, 0xB7, 0xB7, 0xBF, 0xBF, 0xFF },  //F
  { 0xFF, 0xC1, 0x80, 0xBE, 0xBA, 0x98, 0xD9, 0xFF },  //G
  { 0xFF, 0x80, 0x80, 0xF7, 0xF7, 0x80, 0x80, 0xFF },  //H
  { 0xFF, 0xFF, 0xBE, 0x80, 0x80, 0xBE, 0xFF, 0xFF },  //I
  { 0xFF, 0xF9, 0xF8, 0xBE, 0x80, 0x81, 0xBF, 0xFF },  //J
  { 0xFF, 0x80, 0x80, 0xE3, 0xC9, 0x9C, 0xBE, 0xFF },  //K
  { 0xFF, 0x80, 0x80, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF },  //L
  { 0xFF, 0x80, 0x80, 0xCF, 0xE7, 0xCF, 0x80, 0x80 },  //M
  { 0xFF, 0x80, 0x80, 0xCF, 0xE7, 0xF3, 0x80, 0x80 },  //N
  { 0xFF, 0xC1, 0x80, 0xBE, 0xBE, 0x80, 0xC1, 0xFF },  //O
  { 0xFF, 0x80, 0x80, 0xBB, 0xBB, 0x83, 0xC7, 0xFF },  //P
  { 0xFF, 0xC3, 0x81, 0xBD, 0xBD, 0x80, 0xC2, 0xFF },  //Q
  { 0xFF, 0x80, 0x80, 0xB3, 0xB1, 0x84, 0xCE, 0xFF },  //R
  { 0xFF, 0xCD, 0x84, 0xB6, 0xB6, 0x90, 0xD9, 0xFF },  //S
  { 0xFF, 0x9F, 0xBF, 0x80, 0x80, 0xBF, 0x9F, 0xFF },  //T
  { 0xFF, 0x81, 0x80, 0xFE, 0xFE, 0x80, 0x80, 0xFF },  //U
  { 0xFF, 0x83, 0x81, 0xFC, 0xFC, 0x81, 0x83, 0xFF },  //V
  { 0xFF, 0x80, 0x80, 0xF9, 0xF3, 0xF9, 0x80, 0x80 },  //W
  { 0xFF, 0x9C, 0x88, 0xE3, 0xF7, 0xE3, 0x88, 0x9C },  //X
  { 0xFF, 0x8F, 0x87, 0xF0, 0xF0, 0x87, 0x8F, 0xFF },  //Y
  { 0xFF, 0xBC, 0xB8, 0xB2, 0xA6, 0x8E, 0x9E, 0xFF },  //Z

  { 0xFF, 0xFE, 0xEE, 0x80, 0x80, 0xFE, 0xFE, 0xFF },  //1
  { 0xFF, 0xDC, 0x98, 0xBA, 0xB6, 0x86, 0xCE, 0xFF },  //2
  { 0xFF, 0xDD, 0x9C, 0xB6, 0xB6, 0x80, 0xC9, 0xFF },  //3
  { 0xFF, 0xF3, 0xEB, 0xDB, 0x80, 0x80, 0xFB, 0xFF },  //4
  { 0xFF, 0x8D, 0x8C, 0xAE, 0xAE, 0xA0, 0xB1, 0xFF },  //5
  { 0xFF, 0xC1, 0x80, 0xB6, 0xB6, 0x90, 0xD9, 0xFF },  //6
  { 0xFF, 0x9F, 0x9F, 0xB8, 0xA0, 0x87, 0x9F, 0xFF },  //7
  { 0xFF, 0xC9, 0x80, 0xB6, 0xB6, 0x80, 0xC9, 0xFF },  //8
  { 0xFF, 0xCD, 0x84, 0xB6, 0xB6, 0x80, 0xC1, 0xFF },  //9
  { 0xFF, 0xC1, 0x80, 0xAE, 0xB6, 0x80, 0xC1, 0xFF },  //0
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },  //space
  { 0XFF, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },  //.
  { 0XFF, 0x9D, 0x99, 0xF3, 0xE7, 0xCC, 0xDC, 0xFF },  //%
  { 0xFF, 0x3F, 0xC1, 0x80, 0xBE, 0xBE, 0x9C, 0xFF },  //celcius

};
byte cot[8] = { 1, 2, 4, 8, 16, 32, 64, 128 }; // tuong ung voi cot 1 -> cot 8 (tuy theo huong doc cua IC)
char character[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ' ', '.', '%', 'c' };
byte led[][8] = {
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
};
uint8_t ledCount = sizeof(led) / sizeof(led[0]); // So luong man hinh
String temp, humidity, text;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(ST_CP, OUTPUT);  //RCLK

  pinMode(DS_hang, OUTPUT);     //SER hang
  pinMode(SH_CP_hang, OUTPUT);  //SRCLK hang

  pinMode(SH_CP_cot, OUTPUT);  //SRCLK cot
  pinMode(DS_cot, OUTPUT);     //SER cot

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(0, chuyenCheDo, RISING);  //ngat 0 = pin 2
  attachInterrupt(1, chuyenModeManual, RISING); //ngat 1 = pin 3
}

//bool enable = true;
uint8_t mode = 0;
uint8_t currentMode = 0;

void boardWipe(){
    for(int i = 0; i < ledCount; i++){
      for(int j = 0; j < 8; j++) led[i][j] = 0xFF;
  }
  Serial.println("");
  Serial.println("Xoa man hinh!");
}

void chuyenCheDo() {
  if(mode == 0) Serial.println("He thong dang trong che do AUTO");
  else{
    boardWipe();
    mode = 0;
    Serial.println("");
    Serial.println("Doi sang che do AUTO");
  }
}

void chuyenModeManual() {
  boardWipe();
  if(mode == 0) Serial.println("AUTO -> MANUAL");
  mode++;
  if(mode > 2) mode = 1;
  Serial.println("");
  Serial.println("Chuyen sang hoat anh " + String(mode));
}

void loop() {
  currentMode = mode;
  temp = String(dht.readTemperature());
  humidity = String((int)dht.readHumidity());
  text = temp + "c " + humidity + "%";
  switch (mode) {
    case 1:
      hienthia(text, 20, 32); //Chuoi hien thi, do tre(cang > cang cham), cach khoang trong
      break;
    case 2:
      hienthib(text, 20, 32);
      break;
    default: // MODE AUTO
      hienthia(text, 20, 40);
      hienthib(text, 20, 40);
      break;
  } 
}


void hienthia(String tukhoa, uint8_t delay, uint8_t space) {
  if(currentMode != mode) return; // Neu doi mode thi return
  Serial.println("--Anim A--");
  Serial.println("Nhiet do: " + temp + "'C | Do am: " + humidity + "% | Do tre: " + delay + " | Cach doan: " + space);
  for (int q = 0; q < tukhoa.length(); q++) { // Doc tung chu cai trong chuoi
    for (int e = 0; e < sizeof(character); e++) { // Kiem tra chu cai do co ton tai trong bang ve
      if (tukhoa.charAt(q) == character[e]) {
        uint8_t index = 8;
        if (character[e] == '.') index = 4; // Binh thuong ve 7 cot, neu la dau cham thi ve 3 cot (bo qua cot cuoi, co the them cot cuoi)
        for (byte h = 0; h < index-1; h++) {
          if(currentMode != mode) return; 
          for (byte j = 0; j < 7; j++) {
            led[0][j] = led[0][j + 1]; // Dich cot -> cot (man hinh ngoai cung)
          }
          led[0][7] = chu[e][h];
          for (byte w = 0; w < delay; w++) {
            scan(); // Dich bit ra ngoai man hinh
          }
          for (int d = ledCount - 1; d > 0; d--) { // Dich cot -> cot (cac man hinh ben trong)
            for (byte j = 0; j < 7; j++) {
              led[d][j] = led[d][j + 1]; 
            }
            led[d][7] = led[d - 1][0];
          }
        }
      }
    }
    
    if (q == tukhoa.length() - 1) {  // Tao khoang trong (hoat dong tuong tu nhu tren)
      for (byte h = 0; h < space; h++) {
        if(currentMode != mode) return;
        for (byte j = 0; j < 7; j++) {
          led[0][j] = led[0][j + 1];
        }
        led[0][7] = 0xFF;
        for (byte w = 0; w < delay; w++) {
          scan();
        }
        for (int d = ledCount - 1; d > 0; d--) {
          for (byte j = 0; j < 7; j++) {
            led[d][j] = led[d][j + 1];
          }
          led[d][7] = led[d - 1][0];
        }
      }
    }
  }
}

void hienthib(String tukhoa, uint8_t delay, uint8_t space) {
  if(currentMode != mode) return;
  Serial.println("--Anim B--");
  Serial.println("Nhiet do: " + temp + "'C | Do am: " + humidity + "% | Do tre: " + delay + " | Cach doan: " + space);
  for (int q = tukhoa.length() - 1; q >= 0; q--) {
    for (int e = 0; e < sizeof(character); e++) {
      if (tukhoa.charAt(q) == character[e]) {
        uint8_t index = 8;
        if (character[e] == '.') index = 4;
        for (byte h = index - 1; h > 0; h--) {
          if(currentMode != mode) return;
          for (byte j = 0; j < 7; j++) {
            led[0][j] = led[0][j + 1];
          }
          led[0][7] = chu[e][h];
          for (byte w = 0; w < delay; w++) {
            bscan();
          }
          for (int d = 3; d > 0; d--) {
            for (byte j = 0; j < 7; j++) {
              led[d][j] = led[d][j + 1];
            }
            led[d][7] = led[d - 1][0];
          }
        }

        if (q == 0) {  ///// tao khoang trong
          for (byte h = 0; h < space; h++) {
            if(currentMode != mode) return;
            for (byte j = 0; j < 7; j++) {
              led[0][j] = led[0][j + 1];
            }
            led[0][7] = 0xFF;
            for (byte w = 0; w < delay; w++) {
              bscan();
            }
            for (int d = ledCount - 1; d > 0; d--) {
              for (byte j = 0; j < 7; j++) {
                led[d][j] = led[d][j + 1];
              }
              led[d][7] = led[d - 1][0];
            }
          }
        }
      }
    }
  }
}

void scan() {
  for (byte i = 0; i < 8; i++) {
    digitalWrite(ST_CP, LOW); // tat Latch -> bat dau qua trinh dich bit vao trong IC
    for (int l = 0; l < ledCount; l++) shiftOut(DS_hang, SH_CP_hang, LSBFIRST, led[l][i]); //dich bit vao trong 74HC595(theo hang)
    shiftOut(DS_cot, SH_CP_cot, MSBFIRST, cot[i]); //(theo cot) (MSBFIRST: doc tu phai -> trai, LSBFIRST: doc tu trai -> phai)
    digitalWrite(ST_CP, HIGH); // bat Latch -> dich bit ra ngoai man hinh
  }
}

void bscan() {
  for (byte i = 0; i < 8; i++) {
    digitalWrite(ST_CP, LOW);
    for (int l = ledCount-1; l >= 0; l--) shiftOut(DS_hang, SH_CP_hang, LSBFIRST, led[l][i]);
    shiftOut(DS_cot, SH_CP_cot, LSBFIRST, cot[i]);
    digitalWrite(ST_CP, HIGH);
  }
}
