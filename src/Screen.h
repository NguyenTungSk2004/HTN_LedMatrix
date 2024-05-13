#ifndef Screen_h
#define Screen_h

#include <data.h>

void scan() {
    for (byte i = 0; i < 8; i++) {
        digitalWrite(ST_CP, LOW); // turn off Latch -> start shifting bits into the IC
        for (int l = 0; l < ledCount; l++) shiftOut(DS_hang, SH_CP_hang, LSBFIRST, led[l][i]); // shift bits into the 74HC595 (row-wise)
        shiftOut(DS_cot, SH_CP_cot, MSBFIRST, cot[i]); // (column-wise) (MSBFIRST: read from right to left, LSBFIRST: read from left to right)
        digitalWrite(ST_CP, HIGH); // turn on Latch -> shift bits out to the screen
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

void boardWipe(){
    for(int i = 0; i < ledCount; i++){
        for(int j = 0; j < 8; j++) led[i][j] = 0xFF;
    }
}

void hienthia(String tukhoa, uint8_t delay, uint8_t space) {
    if(currentMode != mode) return; // If mode has changed, return
    Serial.println("--Anim A--");
    Serial.println("Nhiet do: " + temp + "'C | Do am: " + humidity + "% | Do tre: " + delay + " | Cach doan: " + space);
    for (int q = 0; q < tukhoa.length(); q++) { // Iterate through each character in the string
        for (int e = 0; e < sizeof(character); e++) { // Check if the character exists in the character array
            if (tukhoa.charAt(q) == character[e]) {
                uint8_t index = 8;
                if (character[e] == '.') index = 4; // Normally draw 7 columns, if it's a dot, draw 3 columns (skip the last column, can add the last column if needed)
                for (byte h = 0; h < index-1; h++) {
                    if(currentMode != mode) return; 
                    for (byte j = 0; j < 7; j++) {
                        led[0][j] = led[0][j + 1]; // Shift columns to the left (outer screen)
                    }
                    led[0][7] = chu[e][h];
                    for (byte w = 0; w < delay; w++) {
                        scan(); // Shift bits out to the screen
                    }
                    for (int d = ledCount - 1; d > 0; d--) { // Shift columns to the left (inner screens)
                        for (byte j = 0; j < 7; j++) {
                            led[d][j] = led[d][j + 1]; 
                        }
                        led[d][7] = led[d - 1][0];
                    }
                }
            }
        }
        
        if (q == tukhoa.length() - 1) {  // Create spacing (similar operation as above)
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

                if (q == 0) {  ///// Create spacing
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


#endif
