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
BH1750 | V1.0 | 05.2023

*/

#include <Arduino.h>
#include <Wire.h>
#include <BH1750.h>

unsigned long previousMillis = millis();

BH1750 lxMeter;

void setup()
{
  Serial.begin(115200);

  Wire.begin();
  lxMeter.begin();

  Serial.println("Setup finished");
}

void loop()
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (1000 * 2))
  {
    previousMillis = currentMillis;

    float lux = lxMeter.readLightLevel();
    Serial.print("Light: ");
    Serial.print(lux);
    Serial.println(" lx");
  }
}