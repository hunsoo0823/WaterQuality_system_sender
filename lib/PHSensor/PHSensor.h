#ifndef PHSensor_h
#define PHSensor_h

#include "Arduino.h"

#define ArrayLenthPH 40
#define OFFSET 0 


class PHSensor
{
    private:
        int _PHAnalogpin;
        int PHArray[ArrayLenthPH];
        int PHArrayIndex=0;

    public:
        PHSensor(int PHAnalogpin);
        void getAnalogPH();
        double AvgPH(int *arr, int arrayLth);
        double PH;      
    
};

#endif