#ifndef _DOBOT_AI_H_
#define _DOBOT_AI_H_


//#include <avr/iom256rfr2.h>
#include "MotorControl.h"
#include "IrSensors.h"
#include "USSensor.h"
#include "Beep.h"
#include "E2PROM.h"
#include "GyroSensor.h"


// PINS DEFINITION
#define BUZZER_PIN 11

// FUNCTIONS DEFINITION
extern void beep(int freq, long duration=200);

#endif





