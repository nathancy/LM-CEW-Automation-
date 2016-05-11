/*******************************
 *
 * File: CapacitorOneTest.ino
 *
 * Isolated module to test sensitivity and position of liquid metal
 *
 * ****************************/

/* External library */
#include <CapacitiveSensor.h>

/* On microcontroller: (Resistor, wire) pins */
/* Create sensor objects */
CapacitiveSensor cs_27_29 = CapacitiveSensor(27,29); 
CapacitiveSensor cs_35_37 = CapacitiveSensor(35,37); 
CapacitiveSensor cs_43_45 = CapacitiveSensor(43,45);    
CapacitiveSensor cs_51_53 = CapacitiveSensor(51,53);     

/* Variables to hold readings of each sensor */
long total_27_29 = 0;
long total_35_37 = 0;
long total_43_45 = 0;
long total_51_53 = 0;

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
   /* Turn off autocalibrate */
   cs_27_29.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   cs_35_37.set_CS_AutocaL_Millis(0xFFFFFFFF);   
   cs_43_45.set_CS_AutocaL_Millis(0xFFFFFFFF);   
   cs_51_53.set_CS_AutocaL_Millis(0xFFFFFFFF);   
   
   Serial.begin(9600);
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
    /* Continiously poll sensor readings and take average of 10 readings */
    for(int count = 0; count < 10; count++)
    {
      total_27_29 += cs_27_29.capacitiveSensor(5);
      total_35_37 += cs_35_37.capacitiveSensor(5);
      total_43_45 += cs_43_45.capacitiveSensor(5);
      total_51_53 += cs_51_53.capacitiveSensor(5);
      
      delay(30);
    }

    Serial.print("Sensor1 readings: ");
    Serial.print(total_27_29/10);
    Serial.print("\t");
    Serial.print("Sensor2 readings: ");
    Serial.print(total_35_37/10);
    Serial.print("\t");
    Serial.print("Sensor3 readings: ");
    Serial.print(total_43_45/10);
    Serial.print("\t");
    Serial.print("Sensor4 readings: ");
    Serial.print(total_51_53/10);
    Serial.print("\t");
                   
    Serial.print("\n");

    total_27_29 = 0;
    total_35_37 = 0;
    total_43_45 = 0;
    total_51_53 = 0;

    // Arbitrary delay to limit data to serial port 
    delay(10);                            
}
