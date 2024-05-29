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


Seite 7
1011100 1 ACK HIGH BYTE ACK low byte
in Pulseview Aufnahme kommt bei highbyte = 36
36 / 1,2 (lt Datensheet) = 30 lux


Bei 00000001 und 00010000
(1 x 256) + 16
272 / 1,2 = 227

*/

#include <Arduino.h>
#include <Wire.h>

int BH1750address = 0x23; // I2C address
byte buff[2];
unsigned long previousMillis = millis();

void setup()
{
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Setup fertig");
}

void loop()
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (5000 * 1))
  {
    previousMillis = currentMillis;

    Wire.beginTransmission(BH1750address);
    Wire.write(0x10); // 1lx reolution 120ms H-Resolution Mode Seite 5
    Wire.endTransmission();
    delay(200);

    Wire.requestFrom(BH1750address, 2);
    while (Wire.available()) //
    {
      buff[0] = Wire.read(); // MSB
      buff[1] = Wire.read(); // LSB
    }

    Serial.println(buff[0],BIN);

    // Seite 7 - Berechnung der Beleuchtungsstärke
    // (MSB x 256 + LSB) / 1.2 --> ergibt die nächste Zeile
    int val = ((buff[0] << 8) | buff[1]) / 1.2;

    Serial.print(val);
    Serial.println("lx");
  }
}
