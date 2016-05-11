/****************************************
 * 
 * File: CapacitorVoltage.ino
 *      
 * Isolated module to test voltage trigger
 *    
 ****************************************/
 
/* External/program libraries */
#include <CapacitiveSensor.h>
#include "config.h"

/* Create instance of sensor object */
CapacitiveSensor cs_51_53(51, 53);  
int voltage_count = 0;

/******************************
 * 
 * Name:        setup
 * Returns:     Nothing
 * Parameter:   Nothing
 * Description: Runs once at the start of the program.
 *              Used for initialization.
 * 
 ******************************/
void setup()                    
{
   /* Initialization */
   cs_51_53.set_CS_AutocaL_Millis(0xFFFFFFFF);    
   Serial.begin(9600);
   pinMode(VOLTAGE_PIN, OUTPUT);
   digitalWrite(VOLTAGE_PIN, LOW);
}

/******************************
 * 
 * Name:        loop
 * Returns:     Nothing
 * Parameter:   Nothing
 * Description: Voltage will be logical low (0V) then logical high (5V)
 * 
 ******************************/
void loop()                    
{
    /* Initially low voltage */
    voltage_count++;
    Serial.println("LOW");
    Serial.println(voltage_count);

    /* Switch to high voltage */
    if(voltage_count >= 100)
    {
      digitalWrite(VOLTAGE_PIN, HIGH);
      //digitalWrite(VOLTAGE_PIN, LOW);
      Serial.println("HIGH");
      voltage_count = 0;
    }
    
    Serial.print("\n");
    delay(100);                         
}
