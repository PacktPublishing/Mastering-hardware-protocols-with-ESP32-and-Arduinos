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
#include <SoftwareSerial.h>
// Transmitter
const byte rxPin = 5;
const byte txPin = 6;
SoftwareSerial arduinoUnoTransmitter(rxPin, txPin);

byte btn = 4;
int btnState;
unsigned long buttonDownMs;

void setup()
{
  Serial.begin(115200);
  arduinoUnoTransmitter.begin(9600);
  pinMode(btn, INPUT);
  Serial.println("Arduino Transmitter starts...");
}

void loop()
{
  
  int prevState = btnState;
  btnState = digitalRead(btn);

  // Debounce Button
  if (prevState == HIGH && btnState == LOW)
  {
    buttonDownMs = millis();
  }
  else if (prevState == LOW && btnState == HIGH)
  {
    if (millis() - buttonDownMs < 50)
    {
      // ignore this for debounce
    }
    else
    {
      Serial.println("Btn pressed");
      arduinoUnoTransmitter.println("btn");
    }
  }


 
}