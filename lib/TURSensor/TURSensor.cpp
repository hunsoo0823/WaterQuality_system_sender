#include "Arduino.h"
#include "TURSensor.h"

TURSensor::TURSensor(int TURAnalogpin)
{
    _TURAnalogpin = TURAnalogpin;
}

void TURSensor::getAnalogTUR()
{
    TURValue =analogRead(_TURAnalogpin);

    TUR = TURValue * ( VOLTAGE / 1024.0 );
}


    