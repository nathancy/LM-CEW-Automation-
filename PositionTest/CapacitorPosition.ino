#include <CapacitiveSensor.h>
#include "config.h"

/* Resistor, Wire */

CapacitiveSensor cs_51_53 = CapacitiveSensor(51,53);       
int position;

void setup()                    
{
   cs_51_53.set_CS_AutocaL_Millis(0xFFFFFFFF);    
   Serial.begin(9600);
   Serial.print("Enter position(1-");
   Serial.print(CELLS);
   Serial.print("): ");
}


void loop()                    
{
    
    /* Wait here until input buffer has character */
    if(Serial.available() > 0)
    {
     position = Serial.parseInt();
     Serial.print(position);
     Serial.print("\n");
     
     Serial.print("Enter position(1-");
     Serial.print(CELLS);
     Serial.print("): ");
    }

    delay(10);                             /* arbitrary delay to limit data to serial port */ 
}
