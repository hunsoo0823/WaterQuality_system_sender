#include <TDSSensor.h>
#include <PHSensor.h>
#include <ORPSensor.h>
#include <DOSensor.h>
#include <TURSensor.h>
#include <SPI.h>
#include <LoRa.h>

ORPSensor orpSensor(A1);
PHSensor phSensor(A2);
TDSSensor tdsSensor(A3);
DOSensor doSensor(A4);
TURSensor turSensor(A5);

#define LED 13
#define samplingInterval 20 
#define printInterval 2000

void setup() {
    Serial.begin(9600);
    while (!Serial);

    Serial.println("LoRa Sender");

    if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
     static unsigned long samplingTime=millis();   //analog sampling interval
     static unsigned long printTime=millis();
  
     
//     digitalWrite(LED_BUILTIN, HIGH);
//     delay(100); 
//     digitalWrite(LED_BUILTIN, LOW);
//     delay(100);
     if(millis()- samplingTime > samplingInterval)
     {  
        orpSensor.getAnalogORP();
        phSensor.getAnalogPH();
        tdsSensor.getAnalogTDS();
        doSensor.getAnalogDO();
        turSensor.getAnalogTUR();
        samplingTime = millis();
     }
     
     if(millis() - printTime > printInterval)
     {
        LoRa.beginPacket();
 
        Serial.println("-------------------");
        Serial.print("    ORP value: ");
        Serial.println((int)orpSensor.ORP);
        LoRa.print((int)orpSensor.ORP);
        LoRa.print(" ");
        Serial.print("    pH value: ");
        Serial.println(phSensor.PH,2);
        LoRa.print(phSensor.PH,2);
        LoRa.print(" ");
        Serial.print("    TDS value: ");
        Serial.println(tdsSensor.TDS,0);
        LoRa.print(tdsSensor.TDS,0);
        LoRa.print(" ");
        Serial.print("    DO value: ");
        Serial.println(doSensor.DO);
        LoRa.print(doSensor.DO);
        LoRa.print(" ");
        Serial.print("    TUR value: ");
        Serial.println(turSensor.TUR);
        LoRa.print(turSensor.TUR);
        LoRa.print(" ");
        Serial.println("-------------------");
        printTime = millis(); 
    
        LoRa.endPacket();
     }

}