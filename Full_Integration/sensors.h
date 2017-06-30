/*******************************
 *
 * File: sensors.h
 *
 * Contains prototypes for sensor functions
 *
 * ****************************/

/* Check for previous includes */
#ifndef SENSORS_H
#define SENSORS_H

/* Program libraries */
#include "config.h"

/* Number of sensors used */
#define NUM_SENSORS 4

/* Sensor numbers */
#define RESTART 1000
#define SENSOR1 1
#define SENSOR2 2
#define SENSOR3 3
#define SENSOR4 4

/* Prototypes */

/* Initialize Sensors */
void sensors_Init();

/* Translates user-defined position into internal destination position.
   Continuously polls the sensors and outputs the readings to the serial monitor
   until the liquid metal has reached its desired destination. */
void read_Sensors(int user_position, int metal_position);

/* Get desired destination position from user from serial monitor */
int get_Position();

/* Print position messages to serial monitor */
void print_Position();

/* Determines current position of liquid-metal in channel
   Takes average of 10 sensor readings. Sensor with highest reading corresponds
   to current position of liquid-metal. */
int get_metalPosition();

#endif
