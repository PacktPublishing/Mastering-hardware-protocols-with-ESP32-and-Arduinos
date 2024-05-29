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
SoftwareSerial Arduino UNO | V1.0 | 05.2023
*/

#include <Arduino.h>
#include <SoftwareSerial.h>

const byte rxPin = 5;
const byte txPin = 6;
SoftwareSerial arduinoUnoSerial (rxPin, txPin);

void setup()
{
  Serial.begin(115200);
  arduinoUnoSerial.begin(9600);
}

void loop()
{
  Serial.println("Hello Serial Monitor");
  arduinoUnoSerial.println("Hello PulseView");
  delay(500);
}