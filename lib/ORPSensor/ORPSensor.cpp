#include "Arduino.h"
#include "ORPSensor.h"

ORPSensor::ORPSensor(int OPRAnalogpin)
{
    _ORPAnalogpin = OPRAnalogpin;
}

void ORPSensor::getAnalogORP()
{
    ORPArray[OPRArrayIndex++]=analogRead(_ORPAnalogpin);
    
    if (OPRArrayIndex==ArrayLenthORP) {
      OPRArrayIndex=0;
    }
    ORP=((30*(double)VOLTAGE*1000)-(75*AvgORP(ORPArray, ArrayLenthORP)*VOLTAGE*1000/1024))/75-OFFSET;  
     //convert the analog value to orp according the circuit
}

double ORPSensor::AvgORP(int *arr, int arrlength)
{
  int i;
  int max,min;
  double avg;
  long amount=0;
  if(arrlength<=0){ 
    printf("Error arrlength for the array to avraging!/n");
    return 0;
  }
  if(arrlength<5){   //less than 5, calculated directly statistics
    for(i=0;i<arrlength;i++){
      amount+=arr[i];
    }
    avg = amount/arrlength;
    return avg;
  }else{
    if(arr[0]<arr[1]){
      min = arr[0];max=arr[1];
    }
    else{
      min=arr[1];max=arr[0];
    }
    for(i=2;i<arrlength;i++){
      if(arr[i]<min){
        amount+=min;        //arr<min
        min=arr[i];
      }else {
        if(arr[i]>max){
          amount+=max;    //arr>max
          max=arr[i];
        }else{
          amount+=arr[i]; //min<=arr<=max
        }
      }
    }
    avg = (double)amount/(arrlength-2);
  }
  return avg;
}