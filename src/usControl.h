#ifndef US_CONTROL_H
#define US_CONTROL_H

#include "Arduino.h"

#define ECHO1 56   
#define TRIG1 46    
#define ECHO2 58    
#define TRIG2 6     
#define ECHO3 57    
#define TRIG3 45 
#define SONARDEBUG true 

#define GSONAR_TIME 3000


enum Hcporttag
{
  SONAR1,
  SONAR2,
  SONAR3
};

extern void     sonarsInit();
extern void     sonarInit(int port);
extern float    readDistance(int port);

#endif
