#include "./src/Starter.h"


void setup(){

    // Serial initiation
    Serial.begin(115200);
    // Power On beep
    //beep(2400);
    // Encoders initiation
    EncodersInit();
    //Motors initiation
    MotorInit();


}


void loop(){


   
}