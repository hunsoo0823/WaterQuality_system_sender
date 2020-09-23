#ifndef ORPSensor_h
#define ORPSensor_h

#include "Arduino.h"

#define ArrayLenthORP 40
#define VOLTAGE 5.00    //system voltage
#define OFFSET 0 

class ORPSensor
{
    private:
        int _ORPAnalogpin;
        int ORPArray[ArrayLenthORP];
        int OPRArrayIndex=0;

    public:
        ORPSensor(int ORPAnalogpin);
        void getAnalogORP();
        double AvgORP(int *arr, int arrayLth);
        double ORP;
        
    
};

#endif