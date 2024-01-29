#include "MotorControl.h"
//#include <avr/iom256rfr2.h>

volatile float gCounterR        = 0;
volatile float gLastCounterR    = 0;
volatile float gCounterL        = 0;
volatile float gLastCounterL    = 0;

volatile boolean rPastA   = 0;
volatile boolean rPastB   = 0;
volatile boolean lPastA   = 0;
volatile boolean lPastB   = 0;

volatile unsigned int encoder0Pos = 0;
volatile unsigned int encoder1Pos = 0;

boolean RMA_set = 0;
boolean RMB_set = 0;
boolean LMA_set = 0;
boolean LMB_set = 0;

float value;
int gHWVersion;

#define HIGH_FREQ_EN  1
#define MAX_PWM_VALUE 255

/**
 * @brief Timmer PWM Initiation and Motor Pins Initiation
 * 
 * @return int 
 */
int MotorInit(void){

    TCCR2A = _BV(WGM21) | _BV(WGM20);
    TCCR2B = _BV(CS22);
    TCCR3A = _BV(WGM31) | _BV(WGM30);
    TCCR3B = _BV(CS31);
    TCCR4A = _BV(WGM41) | _BV(WGM40);
    TCCR4B = _BV(CS41);
   
    /* Rigth Motor */
    pinMode(RMA, OUTPUT); 
    pinMode(RMB, OUTPUT); 
    /* Left Motor */
    pinMode(LMA, OUTPUT); 
    pinMode(LMB, OUTPUT); 

    return 0;
}

/**
 * @brief Rigth Motor Control
 * 
 * @param val speed
 * @return int 
 */
int MotorR(int val)
{
    
    
    if (gHWVersion == EDUCATION){
        val = 0.75 * val;
    }else if (gHWVersion == CONTEST){
        val = val;
    }else{
        val = val;
    }

    val = -val;

    if (val > MAX_PWM_VALUE){
        val = MAX_PWM_VALUE;
    }else if (val < -MAX_PWM_VALUE){
        val = -MAX_PWM_VALUE;
    }


    if (val > 0){
        analogWrite(RMA, val);
        analogWrite(RMB, 0);
    }else{
        analogWrite(RMA, 0);
        analogWrite(RMB, -val * 4);
    }
}

/**
 * @brief Left Motor Control
 * 
 * @param val speed
 * @return int 
 */
int MotorL(int val)
{
    
    if (gHWVersion == EDUCATION){
        val = 0.75 * val;
    }else if (gHWVersion == CONTEST){
        val = val;
    }else{
        val = val;
    }

    if (val > MAX_PWM_VALUE){
        val = MAX_PWM_VALUE;
    }else if (val < -MAX_PWM_VALUE){
        val = -MAX_PWM_VALUE;
    }
    
    if (val > 0){
        analogWrite(LMA, val * 4);
        analogWrite(LMB, 0);
    }else{
        analogWrite(LMA, 0);
        analogWrite(LMB, -val);
    }
}

/**
 * @brief Rigth Motor Encoder A Interrupt
 * 
 */
void EncoderRA()
{
    // Low to High transition?
    if (digitalRead(ERMA) == HIGH){

        RMA_set = true;
        if (!RMB_set){
            gCounterR = gCounterR + 1;
        }
    }
    
    // High-to-low transition?
    if (digitalRead(ERMA) == LOW){

        RMA_set = false;
    }
}


/**
 * @brief Rigth Motor Encoder B Interrupt
 * 
 */
void EncoderRB()
{
    // Low-to-high transition?
    if (digitalRead(ERMB) == HIGH){

        RMB_set = true;
        if (!RMA_set){
            gCounterR = gCounterR - 1;
        }
    }
    
    // High-to-low transition?
    if (digitalRead(ERMB) == LOW){
        RMB_set = false;
    }
}

/**
 * @brief Left Motor Encoder A Interrupt
 * 
 */
void EncoderLA()
{
  
    // Low to High transition?
    if (digitalRead(ELMA) == HIGH){

        LMA_set = true;
        if (!LMB_set){
            gCounterL = gCounterL - 1;
        }
    }

    // High-to-low transition?
    if (digitalRead(ELMA) == LOW){
        LMA_set = false;
    }
}

/**
 * @brief Left Motor Encoder B Interrupt
 * 
 */
void EncoderLB()
{
    // Low-to-high transition?
    if (digitalRead(ELMB) == HIGH){

        LMB_set = true;
        if (!LMA_set){
            gCounterL = gCounterL + 1;
        }
    }

    // High-to-low transition?
    if (digitalRead(ELMB) == LOW){
        LMB_set = false;
    }
}

/**
 * @brief Encoders Initiation and interrupt attatchment
 * 
 * @return int 
 */
int EncodersInit()
{
    /*EncoderR*/
    pinMode(ERMA, INPUT); //
    pinMode(ERMB, INPUT); //
    attachInterrupt(2, EncoderRA, CHANGE);
    attachInterrupt(3, EncoderRB, CHANGE);

    /*EncoderL*/
    pinMode(ELMA, INPUT); //
    pinMode(ELMB, INPUT); //
    attachInterrupt(0, EncoderLA, CHANGE);
    attachInterrupt(1, EncoderLB, CHANGE);
    return 0;
}

/**
 * @brief Motors test function
 * 
 */
void MotorsTest(){

    //Move forward for 1 second
    MotorR(255);
    MotorL(255);
    delay(1000);

    //stop car
    MotorR(0);
    MotorL(0);
    delay(1000); 

    //Move backward for 1 second
    MotorR(-255);
    MotorL(-255);
    delay(1000);

    //stop car
    MotorR(0);
    MotorL(0);
    delay(1000); 

}

/**
 * @brief Encoders test function
 * 
 */
void EncodersTest(){
   
    while(1){
        EncoderLA();    
        EncoderLB();
        EncoderRA();    
        EncoderRB();
        Serial.print("R: ");
        Serial.print(gCounterR);
        Serial.print("L: ");
        Serial.println(gCounterL);
        delay(100);
    }

}
