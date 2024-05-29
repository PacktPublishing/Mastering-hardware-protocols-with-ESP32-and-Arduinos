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
I2C Scanner | V1.0 | 02.2023

*/

#include <Arduino.h>
#include <Wire.h>

unsigned long previousMillis = millis();

void setup()
{
  Wire.begin();
  Serial.begin(115200);
}

void loop()
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (20))
  {
    previousMillis = currentMillis;

    byte address, result;

    for (address = 0; address < 127; address++)
    {
      Wire.beginTransmission(address);
      result = Wire.endTransmission();

      if (result == 0)
      {
        Serial.println(address, HEX);
      }
    }

    delay(5000);
  }
}
