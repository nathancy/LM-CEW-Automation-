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
void sensors_Init();
void read_Sensors(int user_position, int metal_position);
int get_Position();
void print_Position();
int get_metalPosition();

#endif
