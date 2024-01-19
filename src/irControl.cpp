#include "irControl.h"

int irInit(){
    pinMode(IR_1_PIN, INPUT);
    pinMode(IR_2_PIN, INPUT);
    pinMode(IR_3_PIN, INPUT);
    pinMode(IR_4_PIN, INPUT);
    pinMode(IR_5_PIN, INPUT);
    pinMode(IR_6_PIN, INPUT);
    return 0;
}

int irDetectPort(int port)
{
    int result = 0;

    switch (port){
    case IR1:
        result = digitalRead(IR_1_PIN);
        break;
    case IR2:
        result = digitalRead(IR_2_PIN);
        break;
    case IR3:
        result = digitalRead(IR_3_PIN);
        break;
    case IR4:
        result = digitalRead(IR_4_PIN);
        break;
    case IR5:
        result = digitalRead(IR_5_PIN);
        break;
    case IR6:
        result = digitalRead(IR_6_PIN);
        break;
    }
    return result;
}

int irDetect(){
    
    int val = 0;

    val |= digitalRead(IR_1_PIN) << 0;
    val |= digitalRead(IR_2_PIN) << 1;
    val |= digitalRead(IR_3_PIN) << 2;
    val |= digitalRead(IR_4_PIN) << 3;
    val |= digitalRead(IR_5_PIN) << 4;
    val |= digitalRead(IR_6_PIN) << 5;

    return val;
}
