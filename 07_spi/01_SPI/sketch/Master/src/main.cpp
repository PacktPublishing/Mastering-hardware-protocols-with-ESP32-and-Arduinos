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

unsigned long previousMillis = millis();

const int SS_PIN = 10; // Slave Select (SS) pin

void setup()
{
  Serial.begin(9600);

  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS, HIGH);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (1000 * 2))
  {
    previousMillis=currentMillis;
    // Select the slave device
    digitalWrite(SS_PIN, LOW);
    // Send 1 byte (8 bits)
    byte dataToSend = 0x0B;
    SPI.transfer(dataToSend);
    digitalWrite(SS_PIN, HIGH);
    Serial.print("Sent: 0x");
    Serial.print(dataToSend, HEX);
  }
}