#include "USSensor.h"
#include <Arduino.h>

#define SONARDEBUG false

int gSonarTime = 3000;
int SonarInit(int port)
{
    switch (port)
    {
    case SONAR1:
        pinMode(TRIG1, OUTPUT);
        pinMode(ECHO1, INPUT);
        break;
    case SONAR2:
        pinMode(TRIG2, OUTPUT);
        pinMode(ECHO2, INPUT);
        break;
    case SONAR3:
        pinMode(TRIG3, OUTPUT);
        pinMode(ECHO3, INPUT);
        break;
    default:
        break;
    }
    return 0;
}

float SonarDetect(int port)
{
    int distance;
    switch (port)
    {
    case SONAR1:
        digitalWrite(TRIG1, LOW); 
        delayMicroseconds(2);
        digitalWrite(TRIG1, HIGH); 
        delayMicroseconds(10);
        digitalWrite(TRIG1, LOW);                    
        distance = pulseIn(ECHO1, HIGH, gSonarTime); 
        if (distance == 0){
            distance = gSonarTime;
        }
        break;
    case SONAR2:
        digitalWrite(TRIG2, LOW); 
        delayMicroseconds(2);
        digitalWrite(TRIG2, HIGH); 
        delayMicroseconds(10);
        digitalWrite(TRIG2, LOW);                    
        distance = pulseIn(ECHO2, HIGH, gSonarTime); 
        if (distance == 0){
            distance = gSonarTime;
        }
        break;
    case SONAR3:
        digitalWrite(TRIG3, LOW); 
        delayMicroseconds(2);
        digitalWrite(TRIG3, HIGH); 
        delayMicroseconds(10);
        digitalWrite(TRIG3, LOW);                    
        distance = pulseIn(ECHO3, HIGH, gSonarTime); 
        if (distance == 0){
            distance = gSonarTime;
        }
        break;
    default:
        break;
    }
    
    float dis = (float)distance / 58; 

    return dis;
}
