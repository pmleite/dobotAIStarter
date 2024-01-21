#include "DobotAI.h"

/**
 * @brief Function to emit a sound in the buzzer
 * 
 */
void beep(int freq, long duration){
    tone(BUZZER_PIN, freq);
    delay(duration);
    noTone(BUZZER_PIN);
};