#ifndef LinePatrol_H
#define LinePatrol_H

#include "Arduino.h"

#define IRMODULBENUM        6      
#define LINEPATROLTARGET    0  

class LINEPATROL
{
public:
    struct Offect{
        float iRModule[IRMODULBENUM];   
        float maxOffect;                
    };
    typedef struct Offect OFFECT; 
    typedef OFFECT *POFFECT; 

    struct Pid{
        float kP;       
        float kI;
        float iValueLimit;     
        float kD;
    };
    
    typedef struct Pid PID;
    typedef PID *PPID;

    struct PIDCalculation{
        float bias;         
        float lastBias;
        float location;
        float lastSpeed;
        float target;
        float pIDLocation;
        float ivalue;
    };

    typedef struct PIDCalculation PIDCALCULATION;
    typedef PIDCALCULATION *PPIDCALCULATION;

    void SetLocationPID(float kP,       
                        float kI,
                        float kILimit,
                        float kD);
   
    void SetLocationDeviation( int iRModule1,
                               int iRModule2,
                               int iRModule3,
                               int iRModule4,
                               int iRModule5,
                               int iRModule6);

    float   getLocation(void);
    int     getIRModuleSetNum(void);
    float   getPIDLocation(void);
    int     locationPID(PIDCALCULATION *pIDParams, PID pID);
    void    linePatrolRun(float location, float speed, float maxOffectSpeed);


};

#endif




