/****************************************
 * 
 * File: CapacitorPosition.ino
 * 
 * Isolated module to test user-input into program
 *    
 ****************************************/

/* External/program libraries */
#include <CapacitiveSensor.h>
#include "config.h"

/* Create instance of sensor */
CapacitiveSensor cs_51_53 = CapacitiveSensor(51,53);       

/* Variable to keep track of user-input */
int position;

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
   Serial.print("Enter position(1-");
   Serial.print(CELLS);
   Serial.print("): ");
}

/******************************
 * 
 * Name:        loop
 * Returns:     Nothing
 * Parameter:   Nothing
 * Description: Main program function, runs constantly.
 *              Executed after setup() and will continue running
 *              indefinitely unless conditions stop it.
 * 
 ******************************/
void loop()                    
{    
    /* Wait here until input buffer has character */
    if(Serial.available() > 0)
    {
     /* Parse serial monitor for valid positional input */
     position = Serial.parseInt();
     Serial.print(position);
     Serial.print("\n");
     
     Serial.print("Enter position(1-");
     Serial.print(CELLS);
     Serial.print("): ");
    }

    /* Arbitrary delay to limit data to serial port */ 
    delay(10);         
}
