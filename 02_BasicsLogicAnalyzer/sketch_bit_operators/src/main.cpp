/*
        _          _ ______ _____ _____
       (_)        | |  ____|  __ \_   _|
  _ __  ___  _____| | |__  | |  | || |
 | '_ \| \ \/ / _ \ |  __| | |  | || |
 | |_) | |>  <  __/ | |____| |__| || |_
 | .__/|_/_/\_\___|_|______|_____/_____|
 | |
 |_|

www.pixeledi.eu | https://linktr.ee/pixeledi
Bit Basics Arduino UNO | V1.0 | 05.2023
*/

#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Hello Bitoperations");

  // // Example
  // byte x = 0b10000111;
  // Serial.println(x, BIN);
  // Serial.println(x, HEX);
  // Serial.println(x, DEC);
  // Serial.println(x);

  // AND OR
  // byte x = 0b000;
  // byte y = 0b111;

  // byte val1 = x & y;
  // byte val2 = x | y;

  // Serial.println(val1, BIN);
  // Serial.println(val2, BIN);

  // byte x2 = 0b1000;
  // byte y2 = 0b0111;

  // byte val3 = x2 | y2;
  // Serial.println(val3, BIN);

  // Bit shift <<
  // byte x = 0b11010100;
  // byte y = x << 4;
  // long y2 = x << 4;
  // long z = x << 4 | 1101;

  // Serial.println(y, BIN);
  // Serial.println(y2, BIN);
  // Serial.println(z, BIN);

  // // bitshift >>
  // byte x = 0b01010000;
  // byte y = x >> 4;

  // Serial.println(y, BIN);  


  // // example
  // byte buff[2];
  // buff[0] = 0b00110000;
  // buff[1] = 0b00010001;
 
  // // high byte = buff[0]
  // // low byte = buff[1]
  // // high and low byte = 11000000010001
                         
  // long val = buff[0] << 8 | buff[1];
  // Serial.println(val, BIN);
  // Serial.println(val);

  // maskieren
  byte x = 0b01101100;
  byte y = 0b00001111;
  byte y2 = 0x0F;
  byte z = x & y;
  byte z2 = x & y2;

  Serial.println(z, BIN);
  Serial.println(z2, BIN);



}

void loop() {
  //nothing to do for me
}