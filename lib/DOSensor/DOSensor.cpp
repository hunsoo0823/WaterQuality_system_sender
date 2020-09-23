#include "Arduino.h"
#include "DOSensor.h"

DOSensor::DOSensor(int DOAnalogpin)
{
    _DOAnalogpin = DOAnalogpin;
}

void DOSensor::getAnalogDO()
{
    DOArray[DOArrayIndex++]=analogRead(_DOAnalogpin);
    if (DOArrayIndex==ArrayLenthDO) {
      DOArrayIndex=0;
    }
    for(int i=0; i<ArrayLenthDO; i++){
      DOArraycopy[i] = DOArray[i];
    }
    float averageVoltage = MedianDO(DOArraycopy, ArrayLenthDO) * (float)VOLTAGE / 1024.0;
    int SaturationDoValue = 14.46 + (int)VOLTAGE + 0.5;
    // doValue = Voltage / SaturantioDoVoltage * SaturationDoValue
    DO = SaturationDoValue * (int)averageVoltage / SaturationDoValue;

    SaturationDoValue = averageVoltage;
}

int DOSensor::MedianDO(int *arr, int arrlength)
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