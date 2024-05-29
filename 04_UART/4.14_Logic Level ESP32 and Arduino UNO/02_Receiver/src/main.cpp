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
UART with ESP3 und Arduino UNO | V1.0 | 05.2023
*/

#include <Arduino.h>
#include <HardwareSerial.h>

unsigned long previousMillis = millis();
HardwareSerial SerialESP32(2); // UART 2 -> Pinout
const byte led = 4;

void setup()
{
  Serial.begin(115200); // Serial Monitor
  SerialESP32.begin(9600, SERIAL_8N1, 16, 17);

  // // Wait for the serial ports to initialize
  while (!Serial && !SerialESP32)
  {
    delay(10);
  }
  pinMode(led, OUTPUT);
  Serial.println("UART ESP32 ready");
}

void loop()
{
  while (SerialESP32.available() > 0)
  {

    // uint8_t byteFromSerial = SerialESP32.read();
    // Serial.println("raw bytes");

    String receivedData = SerialESP32.readString(); // Read the incoming data
 
    receivedData.trim();
    if (receivedData == "btn")
    {
      // toggle LED
      digitalWrite(led, !digitalRead(led));

      Serial.println("toggle LED");
    }
  }
}
