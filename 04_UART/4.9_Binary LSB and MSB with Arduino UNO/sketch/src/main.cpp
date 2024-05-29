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
HardwareSerial Arduino UNO | V1.0 | 05.2023
*/

#include <Arduino.h>
unsigned long previousMillis = millis();

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (300 * 1))
  {
    previousMillis = currentMillis;
    // Serial.write(0x70);
    // Serial.write(0x69);
    // Serial.write(0x78);
    // Serial.write(0x65);
    // Serial.write(0x6C);
    // Serial.write(0x65);
    // Serial.write(0x64);
    // Serial.write(0x69);

    // LSB -->
    // Serial.write(0b01100101);
    // Serial.write(0b01100100);
    // Serial.write(0b01101001);

    // MSB -> edi
    Serial.write(0b10100110);
    Serial.write(0b00100110);
    Serial.write(0b10010110);
  }
}
