#include <CapacitiveSensor.h>
#include "config.h"

/* Resistor, Wire */

CapacitiveSensor cs_51_53 = CapacitiveSensor(51,53);       
int voltage_count = 0;

void setup()                    
{
   cs_51_53.set_CS_AutocaL_Millis(0xFFFFFFFF);    
   Serial.begin(9600);
   pinMode(VOLTAGE_PIN, OUTPUT);
   digitalWrite(VOLTAGE_PIN, LOW);
}

void loop()                    
{
    voltage_count++;
    Serial.println("high");
    Serial.println(voltage_count);
    if(voltage_count >= 100)
    {
      digitalWrite(A0, LOW);
      Serial.println("low");
      voltage_count = 0;
    }
    
    Serial.print("\n");


    delay(100);                             // arbitrary delay to limit data to serial port 
}
