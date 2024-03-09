#ifndef __COLORSENSOR_H
#define __COLORSENSOR_H

#include <Arduino.h>
#include "E2PROM.h"

#define WBBASIC     200

#define Color1_S2   65 
#define Color1_S3   64
#define Color1_OUT  18 
#define ITRNUM1     5
#define Color1_LED  63 

#define Color2_S2   30 
#define Color2_S3   31
#define Color2_OUT  19 
#define ITRNUM2     4
#define Color2_LED  32 

#define TCSTIME     100

enum
{
    COLORSENOR1,
    COLORSENOR2
};

enum
{
    RCOLOR,
    GCOLOR,
    BCOLOR,
    IDLECOLOR
};

extern uint32_t gCount1;
extern uint32_t gCount2;

extern uint32_t gColorCounter1[3], gColorCounter2[3];
extern uint32_t colorCounter1[3], colorCounter2[3];

extern int ColorInit(int port);
extern void ColorPortInit(int port);
extern int ColorDeinit(int port);
extern int ColorWB(int port);

extern void ColorCount1();
extern void ColorCount2();
extern void ColorDetectCallBack2();
extern void ColorDetectCallBack1();

#endif