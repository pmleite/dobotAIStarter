#ifndef _DOBOT_AI_H_
#define _DOBOT_AI_H_


//#include <avr/iom256rfr2.h>
#include "Arduino.h"
#include "Beeper.h"
#include "USSensor.h"
#include "IrSensors.h"
#include "GyroSensor.h"
#include "MotorControl.h"
#include "EEPROM.h"
#include "E2PROM.h"


// PINS DEFINITION
#define BUZZER_PIN 11

// FUNCTIONS DEFINITION
extern void beep(int freq, long duration=200);

#endif





