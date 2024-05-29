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

Wiring
GND <--> GND
A4  <--> A4
A5  <--> A5

*/
#include <Arduino.h>
#include <Wire.h>

unsigned long previousMillis = millis();
const byte slave_addr=9;
const byte answer_size=13;
String receiveData="";

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("I2C Master Setup finished");
}

void loop()
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (500 * 1))
  {
    previousMillis = currentMillis;

    Wire.requestFrom(slave_addr, answer_size);
    receiveData ="";
    while(Wire.available()){
      char c = Wire.read();
      receiveData +=String(c);
    }

    Serial.println(receiveData);

  }
  
}