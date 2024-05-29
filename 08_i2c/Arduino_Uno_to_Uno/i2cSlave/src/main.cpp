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
I2C Arduino UNO to UNO | V1.0 | 05.2023

*/
#include <Arduino.h>
#include <Wire.h>

unsigned long previousMillis = millis();

int randomNumber = 0;

void requestEvent(){
  String txt ="pixelEDI: "+String(randomNumber);
  Wire.write(txt.c_str());
  Serial.println(txt);
} 

void setup()
{
  Wire.begin(9);
  Serial.begin(9600);
  Wire.onRequest(requestEvent);
  randomSeed(analogRead(0));
  Serial.println("I2C Slave Setup finished");
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (500 * 1))
  {
    previousMillis = currentMillis;
    randomNumber = random(100,999);
  }
}