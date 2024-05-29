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
DHT22  | V1.0 | 05.2023

*/

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 26
#define DHTTYPE DHT11
//#define DHTTYPE DHT22

unsigned long previousMillis = millis();

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);
  dht.begin();
}

void loop()
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (1000 * 2))
  {
    previousMillis = currentMillis;
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    float hif = dht.computeHeatIndex(t, h);

    Serial.print("Temp.: ");
    Serial.print(t);
    Serial.print(" Hum.: ");
    Serial.print(h);
    // like a fealt temperature which includes the humidity
    Serial.print(" Heatindex: ");
    Serial.println(hif);
  }
}