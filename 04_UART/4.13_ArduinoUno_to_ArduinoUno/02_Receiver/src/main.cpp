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
Arduino UNO to Arduino UNO via UART | V1.0 | 05.2023
*/

#include <Arduino.h>
#include <SoftwareSerial.h>
// Receiver
const byte rxPin = 2;
const byte txPin = 3;
SoftwareSerial arduinoUnoReceiver(rxPin, txPin);

const byte led = 6;

void setup()
{
  Serial.begin(115200);
  arduinoUnoReceiver.begin(9600);
  Serial.println("Arduino Receiver starts...");
  pinMode(led, OUTPUT);
}

void loop()
{

  // while(arduinoUnoReceiver.available()){
  //   String uartmsg=Serial.readString();
  //    Serial.println(uartmsg);
  // }
  if (arduinoUnoReceiver.available())
  {                                                        // Check if data is available to read
    String receivedData = arduinoUnoReceiver.readString(); // Read the incoming data

    // no whitespace or linebreaks
    receivedData.trim();

    if (receivedData == "btn")
    {
      // toggle LED
      digitalWrite(led, !digitalRead(led));

      Serial.println("toggle LED");
    }
  }
}