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
DS18b20 Onewire | V1.0 | 02.2023

https://arduino.stackexchange.com/questions/67150/ds18b20-with-only-onewire-library

*/

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// zwischen 9 und 12
const byte TEMPERATURE_RESOLUTION_IN_BIT = 12;
const int tempSensor = 5;
OneWire oneWire(tempSensor);
DallasTemperature sensors(&oneWire);

unsigned long previousMillis = millis();

void setup()
{
  Serial.begin(115200);
  sensors.begin();
}

void loop()
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (1000 * 2))
  {
    previousMillis=currentMillis;
    sensors.setResolution(TEMPERATURE_RESOLUTION_IN_BIT);
    sensors.requestTemperatures();
    float tempC = sensors.getTempCByIndex(0);
    float tempF = sensors.getTempFByIndex(0);
    Serial.print(tempC);
    Serial.println("ºC");
    Serial.print(tempF);
    Serial.println("ºF");
  }
}