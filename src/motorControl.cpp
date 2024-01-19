#include "Arduino.h"
#include "motorControl.h"
#include <avr/iom2560.h>


volatile float      gCounterR = 0;
volatile float      gLastCounterR = 0;
volatile float      gCounterL = 0;
volatile float      gLastCounterL = 0;

volatile boolean    rPastA = 0;
volatile boolean    rPastB = 0;
volatile boolean    lPastA = 0;
volatile boolean    lPastB = 0;

volatile unsigned int encoder0Pos = 0;
volatile unsigned int encoder1Pos = 0;

boolean RA_set = 0;
boolean RB_set = 0;
boolean LA_set = 0;
boolean LB_set = 0;

/*PID*/
float value;
int gHWVersion;

int motorsInit(void)
{

if(HIGH_FREQ_EN){
    //timer2  8bit timer
    TCCR2A = _BV(WGM21) | _BV(WGM20);
    TCCR2B = _BV(CS22);
    //timer3  16bit timer
    TCCR3A = _BV(WGM31) | _BV(WGM30);
    TCCR3B = _BV(CS31);
    //timer4  16bit timer
    TCCR4A = _BV(WGM41) | _BV(WGM40);
    TCCR4B = _BV(CS41);
}
    /*MotroR*/
    pinMode(RA, OUTPUT); 
    pinMode(RB, OUTPUT); 
    /*MotorL*/
    pinMode(LA, OUTPUT); 
    pinMode(LB, OUTPUT); 
    /*Init time1*/
    return 0;
}

int motorR(int val)
{
    if (gHWVersion == EDUCATION){
        val = 0.75 * val;
    }
    else{
        val = val;
    }
    if (val > MAX_PWM_VALUE){
        val = MAX_PWM_VALUE;
    }
    else if (val < -MAX_PWM_VALUE){
        val = -MAX_PWM_VALUE;
    }

    if (val > 0){
        analogWrite(RA, val);
        analogWrite(RB, 0);
    }
    else{
        analogWrite(RA, 0);
        if(HIGH_FREQ_EN){
            analogWrite(RB,  -val * 4);
        }else{
            analogWrite(RB, -val);
        }
    }
}

int motorL(int val)
{
    val = -val;
    if (gHWVersion == EDUCATION){
        val = 0.75 * val;
    }
    else{
        val = val;
    }
    if (val > MAX_PWM_VALUE){
        val = MAX_PWM_VALUE;
    }
    else if (val < -MAX_PWM_VALUE){
        val = -MAX_PWM_VALUE;
    }
    if (val > 0){
        if (HIGH_FREQ_EN){
            analogWrite(LA, val * 4);
        }else{
            analogWrite(LA, val);
        }
            analogWrite(LB, 0);
    }
    else{
        analogWrite(LA, 0);
        analogWrite(LB, -val);
    }
}

void EncoderRA()
{
    // Low to High transition?
    if (digitalRead(ERA) == HIGH){
        RA_set = true;
        if (!RB_set){
            gCounterR = gCounterR + 1;
        }
    }
    // High-to-low transition?
    if (digitalRead(ERA) == LOW){
        RA_set = false;
    }
}

void EncoderRB()
{
    // Low-to-high transition?
    if (digitalRead(ERB) == HIGH){
        RB_set = true;
        if (!RA_set){
            gCounterR = gCounterR - 1;
        }
    }
    // High-to-low transition?
    if (digitalRead(ERB) == LOW) {
        RB_set = false;
    }
}

void EncoderLA()
{
    // Low to High transition?
    if (digitalRead(ELA) == HIGH){
        LA_set = true;
        if (!LB_set){
            gCounterL = gCounterL - 1;
        }
    }
    // High-to-low transition?
    if (digitalRead(ELA) == LOW){
        LA_set = false;
    }
}

void EncoderLB()
{
    // Low-to-high transition?
    if (digitalRead(ELB) == HIGH){
        LB_set = true;
        if (!LA_set){
            gCounterL = gCounterL + 1;
        }
    }
    // High-to-low transition?
    if (digitalRead(ELB) == LOW){
        LB_set = false;
    }
}

int motorEncodersInit()
{
    /*EncoderR*/
    pinMode(ERA, INPUT); 
    pinMode(ERB, INPUT); 
    attachInterrupt(2, EncoderRA, CHANGE);
    attachInterrupt(3, EncoderRB, CHANGE);

    /*EncoderL*/
    pinMode(ELA, INPUT); 
    pinMode(ELB, INPUT); 
    attachInterrupt(0, EncoderLA, CHANGE);
    attachInterrupt(1, EncoderLB, CHANGE);
    
    return 0;
}