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


void setup()
{
  //Serial.begin(9600); // 1 / 9600 = 104µs
  Serial.begin(19200); // 1/19200 = 52µs
}

void loop()
{
  Serial.println("Baudrate");
  delay(500);
}