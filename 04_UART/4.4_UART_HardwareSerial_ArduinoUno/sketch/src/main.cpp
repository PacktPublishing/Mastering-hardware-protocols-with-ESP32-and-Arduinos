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
  Serial.begin(115200);
}

void loop()
{
  Serial.println("Hello PulseView");
  delay(500);
}