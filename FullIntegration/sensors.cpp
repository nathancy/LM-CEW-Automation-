
/*******************************
 *
 * File: sensors.cpp
 *
 * Contains definitions for sensor initialization
 *
 * ****************************/

#include <CapacitiveSensor.h>
#include "sensors.h"

/* Create instances of sensors */
CapacitiveSensor cs_51_53(51, 53); 
CapacitiveSensor cs_47_49(47, 49);     

void sensors_Init()
{
	cs_51_53.set_CS_AutocaL_Millis(0xFFFFFFFF);     
	cs_47_49.set_CS_AutocaL_Millis(0xFFFFFFFF);     
}
