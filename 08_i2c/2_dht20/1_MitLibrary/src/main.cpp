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
DHT20 | V1.0 | 05.2023

*/

#include <Arduino.h>
#include <DFRobot_DHT20.h>

unsigned long previousMillis = millis();

// Default I2C address = 0x38
DFRobot_DHT20 dht20;

void setup()
{
  Serial.begin(115200);

  dht20.begin();

  Serial.println("Setup finished");
}

void loop()
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (1000 * 2))
  {
    previousMillis = currentMillis;

    float dht20_temperature = dht20.getTemperature();
    float dht20_humidity = dht20.getHumidity() * 100;

    Serial.println(dht20_temperature);
    Serial.println(dht20_humidity);

  }
}