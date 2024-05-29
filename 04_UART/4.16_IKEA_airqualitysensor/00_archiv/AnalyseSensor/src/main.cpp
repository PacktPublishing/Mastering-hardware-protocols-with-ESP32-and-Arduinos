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
#include <SoftwareSerial.h>

unsigned long previousMillis = millis();
SoftwareSerial SerialESP(D2, D3); // d3 not used

uint8_t serialRxBuf[255];
uint8_t rxBufIdx = 0;

byte buff[20];
byte cnt=0;

void clearRxBuf()
{
  // Clear everything for the next message
  memset(serialRxBuf, 0, sizeof(serialRxBuf));
  rxBufIdx = 0;
}

void setup()
{
  Serial.begin(115200); // Serial Monitor
  SerialESP.begin(9600);

  Serial.println("Setup finished");
}

void loop()
{

  if (SerialESP.available())
  {
    
    // 20 bytes
    // 5 und 6 für auswertung interssant
  
    //jedes byte in array  
    while (SerialESP.available())
    {
       buff[rxBufIdx++]=SerialESP.read();
       Serial.print("~");
    }
    
    // sensor wertet 7x hintereinander 
    // index reset und pm25 ausrechnen
    // durchschnitt könnte man noch einfügen
    if(rxBufIdx>=20){
        int pm25=buff[5]*256 +buff[6];
        Serial.println(pm25);
        rxBufIdx=0;
    }

   

    //   serialRxBuf[rxBufIdx++] = SerialESP.read();
    //   Serial.print(serialRxBuf[rxBufIdx]);

    //   // Without this delay, receiving data breaks for reasons that are beyond me
    //   delay(15);

    //   if (rxBufIdx >= 64)
    //   {
    //     clearRxBuf();
    //   }
    // }
    // const uint16_t pm25 = (serialRxBuf[40] << 8) | serialRxBuf[48];

    // Serial.printf("Received PM 2.5 reading: %d\n", pm25);
    // Serial.println("Done.");

    // byte lowerByte = 0;
    //     for (int i = 48; i < 56; i++)
    // {
    //  lowerByte +=serialRxBuf[i];
    // }


    // Serial.println(lowerByte);
    // Serial.println(lowerByte,BIN);
  }


}
