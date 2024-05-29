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
UART with ESP32 | V1.0 | 05.2023
*/

#include <Arduino.h>
#include <HardwareSerial.h>

unsigned long previousMillis = millis();
HardwareSerial SerialESP32(2); // UART 2 -> Pinout
const byte rxpin = 16;
const byte txpin = 17;

void setup()
{
  Serial.begin(115200); // Serial Monitor
    //https://www.arduino.cc/reference/de/language/functions/communication/serial/begin/ 
 //SerialESP32.begin(115200, SERIAL_8N1, rxpin, txpin); // (8 data bits, no parity, 1 stop bit

  SerialESP32.begin(115200, SERIAL_8E1, rxpin, txpin); // (8 data bits, even parity, 1 stop bit
  //SerialESP32.begin(115200); // Alternative

  // Wait for the serial ports to initialize
  while (!Serial && !SerialESP32)
  {
    delay(10);
  }

  // Print a message on the debug serial port
  Serial.println("ESP32 HardwareSerial Example");
}

void loop()
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (300 * 1))
  {
    previousMillis = currentMillis;
    Serial.println("Hello Serial Monitor");
    SerialESP32.println("Hello PulseView");
  }
}
