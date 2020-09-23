#ifndef TURSensor_h
#define TURSensor_h

#include "Arduino.h"

#define VOLTAGE 5.00    //system voltage
#define OFFSET 0 
#define temperature 25

class TURSensor
{
    private:
        int TURValue;
        int _TURAnalogpin;

    public:
        TURSensor(int TURAnalogpin);
        void getAnalogTUR();
        double TUR;
           
};

#endif