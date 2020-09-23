#ifndef DOSensor_h
#define DOSensor_h

#include "Arduino.h"

#define ArrayLenthDO 30
#define VOLTAGE 5.00    //system voltage
#define OFFSET 0 
#define temperature 25

class DOSensor
{
    private:
        int _DOAnalogpin;
        int DOArray[ArrayLenthDO];
        int DOArraycopy[ArrayLenthDO];
        int DOArrayIndex=0;
        int SaturationDoValue = 1127.6;

    public:
        DOSensor(int DOAnalogpin);
        void getAnalogDO();
        int MedianDO(int *arr, int arrayLth);
        double DO;
        
    
};

#endif

/*
const float SaturationValueTab[41] PROGMEM = {      //saturation dissolved oxygen concentrations at various temperatures
14.46, 14.22, 13.82, 13.44, 13.09,
12.74, 12.42, 12.11, 11.81, 11.53,
11.26, 11.01, 10.77, 10.53, 10.30,
10.08, 9.86,  9.66,  9.46,  9.27,
9.08,  8.90,  8.73,  8.57,  8.41,
8.25,  8.11,  7.96,  7.82,  7.69,
7.56,  7.43,  7.30,  7.18,  7.07,
6.95,  6.84,  6.73,  6.63,  6.53,
6.41,
};
*/