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
#include <SPI.h>

// Arduino UNO fixed SPI GPIOs
// 11 = MOSI
// 12 = MISO
// 13 = SCK
// 10 = SS
const int SS_PIN = 10; // Slave Select (SS) pin

void setup()
{
  Serial.begin(9600);

  SPI.begin();
  pinMode(SS_PIN, INPUT_PULLUP);
  // Configure SPI settings for the slave
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
}

void loop()
{
  if (digitalRead(SS_PIN) == LOW)
  {
    // Receive the data from the master
    byte receivedData = SPI.transfer(0);

    // Print the received data
    Serial.print("Received: 0x");
    Serial.println(receivedData, HEX);
  }
}