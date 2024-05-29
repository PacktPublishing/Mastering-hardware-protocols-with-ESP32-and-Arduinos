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
#include <Wire.h>

int dhtaddress = 0x38;
byte buff[6];

unsigned long previousMillis = millis();

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Serial.println("Setup finished");
}

void loop()
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (1000 * 2))
  {
    previousMillis = currentMillis;

    Wire.beginTransmission(dhtaddress);
    Wire.write(0xAC);
    Wire.write(0x33);
    Wire.write(0x00);
    Wire.endTransmission();

    delay(90);

    Wire.requestFrom(dhtaddress, 6);
    while (Wire.available()) //
    {
      for (size_t i = 0; i < 6; i++)
      {
        buff[i] = Wire.read();
      }
    }

    // byte view
    Serial.print(buff[1], BIN);
    Serial.print(" | ");
    Serial.print(buff[2], BIN);
    Serial.print(" | ");
    Serial.print(buff[3], BIN);
    Serial.print(" | ");

    // Humidity
    byte extractedBits = (buff[3] >> 4); // first 4 bits
    unsigned long hum = buff[1] << 12 | buff[2] << 4 | extractedBits;
    float hum_val = (hum / pow(2, 20)) * 100;
    Serial.println(hum);
    Serial.println(hum_val);

    // Mask the last 4 bits
    byte extractedBits2 = buff[3] & 0x0F;
    long temp = extractedBits2 << 16 | buff[4] << 8 | buff[5];
    float temp_val = (temp / pow(2, 20)) * 200 - 50;
    Serial.println(temp_val);
  }
}