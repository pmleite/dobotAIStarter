#ifndef __MOTOR_H
#define __MOTOR_H

#define RB          5   //PE3 timer3
#define RA          10  //PB4 timer2
#define LB          9   //PH6 timer2
#define LA          8   //PH5 timer4
#define ERA         20  //PD1 INT3
#define ERB         21  //PD0 INT2
#define ELA         3   //PE5 INT1
#define ELB         2   //PE4 INT0

#define EDUCATION   9
#define CONTEST    -1

#define HIGH_FREQ_EN 1
#define MAX_PWM_VALUE 255

extern volatile float gCounterR;
extern volatile float gLastCounterR;
extern volatile float gCounterL;
extern volatile float gLastCounterL;
extern int motorsInit();
extern int motorR(int val);
extern int motorL(int val);
extern int motorEncodersInit();

extern int gHWVersion;
#endif