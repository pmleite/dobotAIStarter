
#include "buzzerControl.h"
#include <avr/iom2560.h>

int BeepInit(void)
{
    pinMode(BEEP_PIN, OUTPUT);
    return 0;
}

int BeepFreq(int fre)
{
    TCCR1B = 0;                      
    TCCR1A = _BV(COM1A0);            
    TCCR1B = _BV(WGM12) | _BV(CS10);                             
    OCR1A = 16000000 / 2 / fre - 1;  
    return 0;
}

int BeepVoice(int ton, int rhythm)
{
    (void)ton;
    (void)rhythm;
    return 0;
}
