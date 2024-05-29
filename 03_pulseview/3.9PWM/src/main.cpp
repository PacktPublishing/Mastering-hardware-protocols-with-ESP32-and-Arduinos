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
Hardwarekommunikation | V1.0 | 05.2023
*/

#include <Arduino.h>
const byte pwm1 = 5;
const byte pwm2 = 6;
const byte digital = 7;

void setup()
{
  Serial.begin(115200);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(digital, OUTPUT);
  Serial.println("Setup finished");
}

void loop()
{
  delay(500);
  analogWrite(pwm1, 20);
  analogWrite(pwm2, 200);
  digitalWrite(digital, HIGH);
  delay(500);
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
  digitalWrite(digital, LOW);

  delay(500);
}