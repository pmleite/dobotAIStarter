#ifndef __BEEP_H
#define __BEEP_H

#include "arduino.h"

#define BEEP 11 //PB5

extern int BeepInit(void);
extern int BeepFre(int fre);

#endif