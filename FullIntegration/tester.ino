#include <CapacitiveSensor.h>
#include "sensors.h"
#include "config.h"
#
/* Resistor, Wire */

long total_51_53 = 0;
long total_47_49 = 0;

void setup()                    
{
   Serial.begin(9600);
   sensors_Init();
}

void loop()                    
{
    for(int count = 0; count < 10; count++)
    {
      total_51_53 += cs_51_53.capacitiveSensor(5);
      total_47_49 += cs_47_49.capacitiveSensor(5);
      
      delay(30);
    }

    Serial.print("Sensor1 readings: ");
    Serial.print(total_51_53/10);
    Serial.print("\t");
    Serial.print("Sensor2 readings: ");
    Serial.print(total_47_49/10);
                   
    Serial.print("\n");

    total_51_53 = 0;
    total_47_49 = 0;

    delay(10);                             // arbitrary delay to limit data to serial port 
}
