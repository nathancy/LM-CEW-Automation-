/*******************************
 *
 * File: sensors.cpp
 *
 * Contains definitions for sensors
 *
 * ****************************/

/* External libraries */
#include <CapacitiveSensor.h>
#include "sensors.h"
#include "voltage.h"

/* Create instances of sensors. On microcontroller: (Resistor, wire) pins */
CapacitiveSensor cs_27_29 = CapacitiveSensor(27,29); 
CapacitiveSensor cs_35_37 = CapacitiveSensor(35,37); 
CapacitiveSensor cs_43_45 = CapacitiveSensor(43,45);    
CapacitiveSensor cs_51_53 = CapacitiveSensor(51,53);    

/******************************
 * 
 * Name:        Sensors_Init
 * Returns:     Nothing
 * Parameter:   Nothing
 * Description: Initialize sensors and disable auto-calibrate
 * 
 ******************************/
void sensors_Init()
{
  /* Disable autocalibrate */
   cs_27_29.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   cs_35_37.set_CS_AutocaL_Millis(0xFFFFFFFF);   
   cs_43_45.set_CS_AutocaL_Millis(0xFFFFFFFF);   
   cs_51_53.set_CS_AutocaL_Millis(0xFFFFFFFF);       
}

/******************************
 * 
 * Name:        get_metalPosition
 * Returns:     Sensor number
 * Parameter:   Nothing
 * Description: Determines current position of liquid-metal in channel
 *              Takes average of 10 sensor readings. Sensor with highest reading corresponds
 *              to current position of liquid-metal.
 *              
 *              Sensor Number (1-4) *Length of channel is 10
 *              Sensor1: 1,2
 *              Sensor2: 3,4,5
 *              Sensor3: 6,7,8
 *              Sensor4: 9,10
 ******************************/
int get_metalPosition()
{
  /* Variables to hold readings for each sensor */
  long total_27_29 = 0;
  long total_35_37 = 0;
  long total_43_45 = 0;
  long total_51_53 = 0;
 
  while(true)
  {
    /* Take average of 10 readings */
    for(int count = 0; count < 10; count++)
    {
      total_27_29 += cs_27_29.capacitiveSensor(5);
      total_35_37 += cs_35_37.capacitiveSensor(5);
      total_43_45 += cs_43_45.capacitiveSensor(5);
      total_51_53 += cs_51_53.capacitiveSensor(5);
      delay(30);
    }

    /* Determine current position of liquid-metal in channel */
    if(total_27_29 > total_35_37 && total_27_29 > total_43_45 && total_27_29 > total_51_53)
    {
      Serial.println("Metal is currently at Sensor1");
      return SENSOR1;
    }
    if(total_35_37 > total_27_29 && total_35_37 > total_43_45 && total_35_37 > total_51_53)
    {
      Serial.println("Metal is currently at Sensor2");
      return SENSOR2;
    }
    if(total_43_45 > total_27_29 && total_43_45 > total_35_37 && total_43_45 > total_51_53)
    {
      Serial.println("Metal is currently at Sensor3");
      return SENSOR3;
    }
    if(total_51_53 > total_27_29 && total_51_53 > total_35_37 && total_51_53 > total_43_45)
    {
      Serial.println("Metal is currently at Sensor4");
      return SENSOR4;
    }
    //delay(10);
  }
}

/******************************
 * 
 * Name:        read_Sensors
 * Returns:     Nothing
 * Parameter:   User-defined position and current liquid metal position in channel
 * Description: Translates user-defined position into internal destination position.
 *              Continuously polls the sensors and outputs the readings to the serial monitor
 *              until the liquid metal has reached its desired destination.
 *              
 *              Sensor Number (1-4) *Length of channel is 10
 *              Sensor1: 1,2
 *              Sensor2: 3,4,5
 *              Sensor3: 6,7,8
 *              Sensor4: 9,10
 * 
 ******************************/
void read_Sensors(int user_position, int metal_position)
{
  /* Variables to hold readings for each sensor */
  long total_27_29 = 0;
  long total_35_37 = 0;
  long total_43_45 = 0;
  long total_51_53 = 0;
  
  /* Variable to hold destination position*/
  int destination;

  /* Translate user-defined position into internal destination */
  if(user_position == 1 || user_position == 2)
    destination = SENSOR1;
  if(user_position == 3 || user_position == 4 || user_position == 5)
    destination = SENSOR2;
  if(user_position == 6 || user_position == 7 || user_position == 8)
    destination = SENSOR3;
  if(user_position == 9 || user_position == 10)
    destination = SENSOR4;

  Serial.println("*************** Metal is currently moving ************************");

  /* Quit if metal is already at desired position */
  if(metal_position == destination)
    Serial.println("Metal is already at desired position");
  else
  {
    /* Continiously poll sensor readings and take average of 10 readings */
    while(metal_position != destination)
    {
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

      /* Internally determine position of liquid metal */
      if(total_27_29 > total_35_37 && total_27_29 > total_43_45 && total_27_29 > total_51_53)
        metal_position = SENSOR1;
      if(total_35_37 > total_27_29 && total_35_37 > total_43_45 && total_35_37 > total_51_53)
        metal_position = SENSOR2;
      if(total_43_45 > total_27_29 && total_43_45 > total_35_37 && total_43_45 > total_51_53)
        metal_position = SENSOR3;
      if(total_51_53 > total_27_29 && total_51_53 > total_35_37 && total_51_53 > total_43_45)
        metal_position = SENSOR4;
        
      total_27_29 = 0;
      total_35_37 = 0;
      total_43_45 = 0;
      total_51_53 = 0;
    
    delay(10);
    }
  }
}

/******************************
 * 
 * Name:        get_Position
 * Returns:     User-defined destination position
 * Parameter:   Nothing
 * Description: Get desired destination position
 * 
 ******************************/
int get_Position()
{
   int position = 0;
   
   print_Position();
   
   /* Wait here until input buffer has character */
   while(position == 0)
   {
     /* Parse serial monitor for valid positional input */
     position = Serial.parseInt();

     /* Get new position if invalid position */
     if(position < 0 || position > CELLS)
     {
       Serial.print("\n");
       Serial.println("Invalid position, try again");
       print_Position();
       position = Serial.parseInt();
     }
   }
   Serial.print(position);
   Serial.print("\n");

   //delay(10);
   return position;
}

/******************************
 * 
 * Name:        print_Position
 * Returns:     Nothing
 * Parameter:   Nothing
 * Description: Print position messages to serial monitor
 * 
 ******************************/
void print_Position()
{
   Serial.print("Enter position(1-");
   Serial.print(CELLS);
   Serial.print("): ");
}



