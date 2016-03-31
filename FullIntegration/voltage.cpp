/* voltage.cpp */

#include "voltage.h"

void voltage_Pin_Init()
{
    pinMode(VOLTAGE_PIN, OUTPUT);
    digitalWrite(VOLTAGE_PIN, LOW);
}

void voltage_On()
{
    digitalWrite(VOLTAGE_PIN, HIGH);
}

