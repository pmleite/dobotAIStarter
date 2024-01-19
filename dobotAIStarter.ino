#include "./src/lineFallower.h"
#include "./src/buzzerControl.h"
#include "./src/irControl.h"
#include "./src/motorControl.h"
#include "./src/usControl.h"


/*PI params*/
float kp = 2.4, ki = 0.0, kd = 0.0;
const float kp_max = 5.0;
const float kp_min = 0.5;
const float ki_max = 0.5;
const float ki_min = 0.05;
/**/
int gPRMR;
int gPRML;

LINEPATROL gLinePatrol;



void setup(){

    // Serial initiation
    Serial.begin(115200);

    // InfraRed initiation
    irInit();
    // Motors and encoders initiation
    motorEncodersInit();
    motorsInit();
    // Ultrasound initiation
    sonarsInit();
    
}


void loop(){


    //motorL(0);
    //MotorR(0);
    // ReadDistance(SONAR1);
    // ReadDistance(SONAR2);
    // ReadDistance(SONAR3);
    // Serial.println(" ");
    // delay(500);
    //Serial.println(IRDetect());
    // Serial.print(IRDetectPort(IR1));
    // Serial.print(IRDetectPort(IR2));
    // Serial.print(IRDetectPort(IR3));
    // Serial.print(IRDetectPort(IR4));
    // Serial.print(IRDetectPort(IR5));
    // Serial.println(IRDetectPort(IR6));

}