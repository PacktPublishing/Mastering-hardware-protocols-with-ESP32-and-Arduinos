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
Trigger | V1.0 | 05.2023

*/

#include <Arduino.h>

const byte irsensor = 3;

void setup()
{
  Serial.begin(115200);
  pinMode(irsensor, INPUT);
}

void loop()
{

  byte IRStatus = digitalRead(irsensor);
  if(IRStatus==1){
    Serial.println("IR Detected!");
    delay(500);
  }

}
