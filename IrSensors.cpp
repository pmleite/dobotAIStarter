#include <Arduino.h>
#include "IrSensors.h"

/**
 * @brief InfraRed Sensors Initiation
 * 
 * @return int 
 */
int IRInit()
{
    pinMode(IR1_PIN, INPUT);
    pinMode(IR2_PIN, INPUT);
    pinMode(IR3_PIN, INPUT);
    pinMode(IR4_PIN, INPUT);
    pinMode(IR5_PIN, INPUT);
    pinMode(IR6_PIN, INPUT);
    return 0;
}

/**
 * @brief InfraRed Sensor Detection
 * 
 * @param port 
 * @return int 
 */
int IRDetectPort(int port)
{
    int result = 0;

    switch (port)
    {
    case IR1:
        result = digitalRead(IR1_PIN);
        break;
    case IR2:
        result = digitalRead(IR2_PIN);
        break;
    case IR3:
        result = digitalRead(IR3_PIN);
        break;
    case IR4:
        result = digitalRead(IR4_PIN);
        break;
    case IR5:
        result = digitalRead(IR5_PIN);
        break;
    case IR6:
        result = digitalRead(IR6_PIN);
        break;
    }
    return result;
}

/**
 * @brief InfraRed Sensors Detection with Bitwise OR 
 * 
 * @return int 
 */
int IRDetect()
{
    int val = 0;

    val |= digitalRead(IR1_PIN) << 0;
    val |= digitalRead(IR2_PIN) << 1;
    val |= digitalRead(IR3_PIN) << 2;
    val |= digitalRead(IR4_PIN) << 3;
    val |= digitalRead(IR5_PIN) << 4;
    val |= digitalRead(IR6_PIN) << 5;

    return val;
}


/**
 * @brief Ir Sensors test function
 * 
 */
void IRTest(){
    int val = 0;
    while (1)
    {
        val = IRDetect();
        Serial.println(val);
        delay(100);
    }
}

