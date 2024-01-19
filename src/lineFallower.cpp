#include "lineFallower.h"
#include "dobotAI.h"

LINEPATROL::PID gPID;
LINEPATROL::OFFECT gOffect;
LINEPATROL::PIDCALCULATION gPIDCalculation;

/**
 * @brief 
 * 
 * @return int 
 */
int LINEPATROL::getIRModuleSetNum(void){
    int Num = 0;
    for (int cir = 0; cir < IRMODULBENUM; cir++){
        if (AIStarter_SmartBotGetIRModuleValue(cir) == 1){
            Num++;
        }
    }
    return Num;
}


/**
 * @brief 
 * 
 * @param iRModule1 
 * @param iRModule2 
 * @param iRModule3 
 * @param iRModule4 
 * @param iRModule5 
 * @param iRModule6 
 */
void LINEPATROL::SetLocationDeviation( int iRModule1,
                                       int iRModule2,
                                       int iRModule3,
                                       int iRModule4,
                                       int iRModule5,
                                       int iRModule6)
{
    gOffect.iRModule[0] = iRModule1;
    gOffect.iRModule[1] = iRModule2;
    gOffect.iRModule[2] = iRModule3;
    gOffect.iRModule[3] = iRModule4;
    gOffect.iRModule[4] = iRModule5;
    gOffect.iRModule[5] = iRModule6;
    gOffect.maxOffect = 0;
    for (int i = 0; i < IRMODULBENUM; i++)
    {
        if ((fabs(gOffect.iRModule[i]) - LINEPATROLTARGET) > gOffect.maxOffect)
        {
            gOffect.maxOffect = gOffect.iRModule[i];
        }
    }
}

/**
 * @brief 
 * 
 * @return float 
 */
float LINEPATROL::getLocation(void)
{
    float location = 0;
    static float lastLocation = 0;
    int num = 0;
    for (int i = 0; i < IRMODULBENUM; i++)
    {
        if (AIStarter_SmartBotGetIRModuleValue(i) == 1)
        {
            location = location + gOffect.iRModule[i];
            num++;
        }
        
    }
    if (num != 0)
    {
        location = location / num;
    }
    else
    {
        location = lastLocation;
    }
    lastLocation = location;
    return location;
}

/**
 * @brief 
 * 
 * @param PIDCalculation 
 * @param pID 
 * @return int 
 */
int LINEPATROL::locationPID(PIDCALCULATION *PIDCalculation, PID pID)
{
    int pivalue = 0;
    PIDCalculation->bias = (PIDCalculation->location - PIDCalculation->target);
    PIDCalculation->ivalue -= PIDCalculation->bias;
    pivalue = pID.kI * PIDCalculation->ivalue;
    if (pivalue > pID.iValueLimit)
    {
        pivalue = pID.iValueLimit;
    }
    else if (pivalue < -pID.iValueLimit)
    {
        pivalue = -pID.iValueLimit;
    }

    PIDCalculation->pIDLocation = pID.kP * PIDCalculation->bias 
                        + pivalue
                        + pID.kD * (PIDCalculation->bias - PIDCalculation->lastBias);
    PIDCalculation->lastBias = PIDCalculation->bias;
    return PIDCalculation->pIDLocation;
}

/**
 * @brief 
 * 
 * @param kP 
 * @param kI 
 * @param kD 
 * @param iValueLimit 
 */
void LINEPATROL::SetLocationPID(float kP,
                                float kI,
                                float kD,
                                float iValueLimit)
{
    gPID.kP = kP;
    gPID.kI = kI;
    gPID.iValueLimit = iValueLimit;
    gPID.kD = kD;
}

/**
 * @brief 
 * 
 * @return float 
 */
float LINEPATROL::getPIDLocation(void)
{
    gPIDCalculation.location = getLocation();
#ifdef __DEBUG
    Serial.print("location: ");
    Serial.println(gPIDCalculation.location);
#endif __DEBUG
    gPIDCalculation.target = LINEPATROLTARGET;
    return locationPID(&gPIDCalculation, gPID);
}


/**
 * @brief 
 * 
 * @param location 
 * @param speed 
 * @param maxOffectSpeed 
 */
void LINEPATROL::linePatrolRun(float location, 
                               float speed, 
                               float maxOffectSpeed)
{
#ifdef __DEBUG
    Serial.print("LinePatrollocation: ");
    Serial.println(location);
#endif __DEBUG
    int speedSlow = 0;			
    if (gOffect.maxOffect != 0)
    {
        speedSlow = speed - (fabs(location) / gOffect.maxOffect * maxOffectSpeed);
    }
#ifdef __DEBUG
    Serial.print("LinePatrolSpeed: ");
    Serial.println(speedSlow);
#endif /* __DEBUG */
    if (location == 0)
    {
        AIStarter_SmartBotSetMotor(MOTORR, speed);
        AIStarter_SmartBotSetMotor(MOTORL, speed);
    }
    else if (location < 0)
    {
        AIStarter_SmartBotSetMotor(MOTORR, speed);
        AIStarter_SmartBotSetMotor(MOTORL, speedSlow);
    }
    else if (location > 0)
    {
        AIStarter_SmartBotSetMotor(MOTORR, speedSlow);
        AIStarter_SmartBotSetMotor(MOTORL, speed);
    }
}



