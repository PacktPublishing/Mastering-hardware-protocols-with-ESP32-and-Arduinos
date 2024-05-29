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
Hardwarekommunikation | V1.0 | 05.2023
*/

#include <Arduino.h>
const byte pin = 8;

void setup()
{
  Serial.begin(115200);
  pinMode(pin, OUTPUT);
  Serial.println("Setup finished");
}

void loop()
{
  digitalWrite(pin, HIGH);
  delay(300);
  digitalWrite(pin, LOW);
  delay(300);
}