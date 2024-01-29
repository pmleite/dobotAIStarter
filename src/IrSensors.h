#ifndef _IRSENSORS_H_
#define _IRSENSORS_H_

#define IR1_PIN 25
#define IR2_PIN 26
#define IR3_PIN 27
#define IR4_PIN 28
#define IR5_PIN 29
#define IR6_PIN 39

enum
{
  IR1 = 0,
  IR2,
  IR3,
  IR4,
  IR5,
  IR6
};

extern int IRInit();
extern int IRDetectPort(int port);
extern int IRDetect();

extern void IRTest();

#endif