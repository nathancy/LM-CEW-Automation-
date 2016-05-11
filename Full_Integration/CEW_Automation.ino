/*******************************
 *
 * File: CEW_Automation.ino
 *
 * Main driver file for CEW automation
 *
 * ****************************/

/* External libraries */
#include <CapacitiveSensor.h>

/* Program libraries */
#include "sensors.h"
#include "config.h"
#include "voltage.h"

/* Global variables for user input and current metal position */
int user_position, metal_position;

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
   /* Initialize baud rate and voltage pins */
   Serial.begin(9600);
   pinMode(VOLTAGE_PIN, OUTPUT);
   digitalWrite(VOLTAGE_PIN, LOW);

   /* Initialize sensors */
   sensors_Init();
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
   /* Get user input and current liquid metal position */
   user_position = get_Position();
   metal_position = get_metalPosition();  

   /* Turn on voltage (translate liquid metal) */
   Serial.println("Voltage is now on");
   digitalWrite(VOLTAGE_PIN, HIGH);

   /* Continiously monitor the liquid metal's position */
   read_Sensors(user_position, metal_position);

   /* Turn off voltage (cease liquid metal movement) */
   digitalWrite(VOLTAGE_PIN, LOW);
   Serial.println("Voltage is now off");
   Serial.println();
}
