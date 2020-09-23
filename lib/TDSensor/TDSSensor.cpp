#include "Arduino.h"
#include "TDSSensor.h"

TDSSensor::TDSSensor(int TDSAnalogpin)
{
    _TDSAnalogpin = TDSAnalogpin;
}

void TDSSensor::getAnalogTDS()
{
    TDSArray[TDSArrayIndex++]=analogRead(_TDSAnalogpin);
    if (TDSArrayIndex==ArrayLenthTDS) {
      TDSArrayIndex=0;
    }
    for(int i=0; i<ArrayLenthTDS; i++){
      TDSArraycopy[i] = TDSArray[i];
    }
    float averageVoltage = MedianTDS(TDSArraycopy, ArrayLenthTDS) * (float)VOLTAGE / 1024.0;
    float compensationCoefficient=1.0+0.02*(temperature-25.0);
    float compensationVolatge=averageVoltage/compensationCoefficient;
    TDS = (133.42*compensationVolatge*compensationVolatge*compensationVolatge - 255.86*compensationVolatge*compensationVolatge + 857.39*compensationVolatge)*0.5;
}

int TDSSensor::MedianTDS(int *arr, int arrlength)
{
  int temparr[arrlength];
  for(int i=0; i< arrlength; i++)
    temparr[i] = arr[i];
  int i,j,temp;
  for(j=0; j< arrlength -1; j++)
  {
    for(i=0; i< arrlength - j - 1; i++)
    {
      if(temparr[i] > temparr[i+1])
      {
        temp = temparr[i];
        temparr[i] = temparr[i+1];
        temparr[i+1] = temp;
      }
    }
  }
  if((arrlength & 1) > 0)
    temp = temparr[(arrlength -1) / 2 ];
  else
    temp = (temparr[arrlength /2] + temparr[arrlength/ 2- 1]) / 2;
  return temp;    
      
      
}