#ifndef _MOTORCONTROL_H_
#define _MOTORCONTROL_H_

#include <Arduino.h>

#define EDUCATION 9 //Compenstation for the education version
#define CONTEST -1  //Compenstation for the contest version

#define RMB 5  //Controlled by timer3
#define RMA 10 //Controlled by timer2
#define LMB 9  //Controlled by timer2
#define LMA 8  //Controlled by timer4

#define ERMA 20 //PD1 attachInterrupt 3
#define ERMB 21 //PD0 attachInterrupt 2
#define ELMA 3  //PE5 attachInterrupt 1
#define ELMB 2  //PE4 attachInterrupt 0

extern volatile float gCounterR;
extern volatile float gLastCounterR;
extern volatile float gCounterL;
extern volatile float gLastCounterL;

extern int gHWVersion;

extern int  MotorInit();
extern int  EncodersInit();
extern int  MotorR(int val);
extern int  MotorL(int val);

extern void MotorsTest();
extern void EncodersTest();

#endif