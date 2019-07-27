#include "Arduino.h"


// 10 bit ADC
#define ADC_MAX_DIGITAL  1024

// Voltage sensor scaling
#define V_SENSOR_SCALE    5

// DAC reference for +5v
#define POS_ADC_REF   5.1  


float Battery_Ampere()
{
  unsigned int average = analogRead(A3);
  float avr =analogRead(A3)*(POS_ADC_REF/ADC_MAX_DIGITAL);
  float SensorValue=(avr-2.55)/0.185;    
  return SensorValue ;
}


float Battery_Voltage()
{
 float analogValue = analogRead(A2);
 Serial.println(analogValue);
 float SensorValue = (POS_ADC_REF/ADC_MAX_DIGITAL)*V_SENSOR_SCALE*analogValue;
 return SensorValue ;
}



float Solar_Voltage()
{ 
  
 float analogValue = analogRead(A4);
 Serial.println(analogValue);
 float SensorValue = (POS_ADC_REF/ADC_MAX_DIGITAL)*V_SENSOR_SCALE*analogValue;
 return SensorValue ;
 
}
float Solar_Ampere()
{
   unsigned int average = analogRead(A1);
   float avr =analogRead(A1)*(POS_ADC_REF/ADC_MAX_DIGITAL);
   float SensorValue=(avr-2.55)/0.185;    
   return SensorValue ;
}

/*

float Solar_Voltage2()
{ 
  
 float analogValue = analogRead(A4);

 Serial.println(analogValue);
 float SensorValue = (POS_ADC_REF1/ADC_MAX_DIGITAL)*V_SENSOR_SCALE*analogValue;
 return SensorValue ;
 
}

float Solar_Ampere2()
{
  unsigned int average = analogRead(A5);
   float avr =analogRead(A1)*(5.1/1024);
  float SensorValue=(avr-2.55)/0.185;    
 return SensorValue ;
}
*/
   
