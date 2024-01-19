#include "usControl.h"

/**
 * @brief Ultrasound sensors initiation
 * 
 */
void sonarsInit()
{
    pinMode(TRIG1, OUTPUT);
    pinMode(ECHO1, INPUT);
    pinMode(TRIG2, OUTPUT);
    pinMode(ECHO2, INPUT);
    pinMode(TRIG3, OUTPUT);
    pinMode(ECHO3, INPUT);
}

/**
 * @brief Initialize one ultrasond sensor
 * 
 * @param port: SONAR1, SONAR2, SONAR3 
 */
void sonarInit(int port)
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
}


/**
 * @brief Read ultrsound one distance
 * 
 * @param port: SONAR1, SONAR2, SONAR3
 * @return float 
 */
float readDistance(int port)
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
        distance = pulseIn(ECHO1, HIGH, GSONAR_TIME); 
        if (distance == 0)
        {
            distance = GSONAR_TIME;
        }
        break;
    case SONAR2:
        digitalWrite(TRIG2, LOW); 
        delayMicroseconds(2);
        digitalWrite(TRIG2, HIGH); 
        delayMicroseconds(10);
        digitalWrite(TRIG2, LOW);                    
        distance = pulseIn(ECHO2, HIGH, GSONAR_TIME); 
        if (distance == 0)
        {
            distance = GSONAR_TIME;
        }
        break;
    case SONAR3:
        digitalWrite(TRIG3, LOW); 
        delayMicroseconds(2);
        digitalWrite(TRIG3, HIGH); 
        delayMicroseconds(10);
        digitalWrite(TRIG3, LOW);                    
        distance = pulseIn(ECHO3, HIGH, GSONAR_TIME); 
        if (distance == 0)
        {
            distance = GSONAR_TIME;
        }
        break;
    default:
        break;
    }
    
    float dis = (float)distance / 58; 
       
    if(SONARDEBUG){
        Serial.print("Sonar ");
        Serial.print(port);
        Serial.print(": ");
        Serial.print(dis);
        Serial.print(" cm     ");  
    } 

    return dis;
}
