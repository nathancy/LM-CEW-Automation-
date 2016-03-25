#include <CapacitiveSensor.h>
/* Resistor, Wire */

CapacitiveSensor cs_51_53 = CapacitiveSensor(51,53); 
CapacitiveSensor cs_47_49 = CapacitiveSensor(47,49);     
       
long total_51_53 = 0;
long total_47_49 = 0;

void setup()                    
{
   /* Turn off autocalibrate */
   cs_51_53.set_CS_AutocaL_Millis(0xFFFFFFFF);    
   cs_47_49.set_CS_AutocaL_Millis(0xFFFFFFFF);    
   Serial.begin(9600);
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
