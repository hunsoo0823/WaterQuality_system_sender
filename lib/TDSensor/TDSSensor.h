#ifndef TDSSensor_h
#define TDSSensor_h

#include "Arduino.h"

#define ArrayLenthTDS 30
#define VOLTAGE 5.00    //system voltage
#define OFFSET 0 
#define temperature 25

class TDSSensor
{
    private:
        int _TDSAnalogpin;
        int TDSArray[ArrayLenthTDS];
        int TDSArraycopy[ArrayLenthTDS];
        int TDSArrayIndex=0;

    public:
        TDSSensor(int TDSAnalogpin);
        void getAnalogTDS();
        int MedianTDS(int *arr, int arrayLth);
        double TDS;
        
    
};

#endif