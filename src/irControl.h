#ifndef IR_CONTROL_H
#define IR_CONTROL_H

#include "Arduino.h"

//InfraRed sensors pins
#define IR_1_PIN    25
#define IR_2_PIN    26
#define IR_3_PIN    27
#define IR_4_PIN    28
#define IR_5_PIN    29
#define IR_6_PIN    3

// Infrared enum
enum
{
  IR1 = 0,
  IR2,
  IR3,
  IR4,
  IR5,
  IR6
};

extern int irInit();
extern int irDetectPort(int port);
extern int irDetect();

#endif