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
SPI UNO | V1.0 | 05.2023
*/

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"
#include <SPI.h>

// Arduino UNO fixed SPI GPIOs
// 11 = MOSI
// 12 = MISO
// 13 = SCK
// 10 = SS

#define DHTPIN 5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
unsigned long previousMillis = millis();

const int SS_PIN = 10; // Slave Select (SS) pin

void setup()
{
  Serial.begin(9600);
  dht.begin();

  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS, HIGH);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (1000 * 2))
  {
    previousMillis = currentMillis;
    float hum = dht.readHumidity();
    float tmp = dht.readTemperature();

    // Select the slave device
    digitalWrite(SS_PIN, LOW);
    SPI.transfer(tmp);
    digitalWrite(SS_PIN, HIGH);

    Serial.print("Temperature: ");
    Serial.print(tmp);
    Serial.println("°C");
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.println(" %");
  }
}