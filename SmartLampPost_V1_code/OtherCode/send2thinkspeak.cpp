#include "send2thinkspeak.h"


#include <SoftwareSerial.h>
#include "Arduino.h"

extern SoftwareSerial mySerial;

void ShowSerialData();

// #define LOG_PRINT   1


void Send2thingspeak(String Y,float X)
{ 
   Serial.println("2SIM: AT+CIPSHUT");
   mySerial.println("AT+CIPSHUT");
   delay(1000);
   ShowSerialData();
   delay(1000);
 #ifdef LOG_PRINT
   Serial.println("2SIM: AT");
 #endif
   mySerial.println("AT");
   delay(1000);
   ShowSerialData();
 #ifdef LOG_PRINT
   Serial.println("2SIM: AT+CGATT=1");
 #endif
   mySerial.println("AT+CGATT=1");
   delay(1000);
   ShowSerialData();
#ifdef LOG_PRINT
   Serial.println("2SIM: AT+CIPMUX");
#endif
   mySerial.println("AT+CIPMUX?");
   delay(1000); 
   ShowSerialData();

#ifdef LOG_PRINT
   Serial.println("2SIM: AT+CSTT=");
#endif
   mySerial.println("AT+CSTT=\"internet\",\"\",\"\"");    //AT+CSTT="internet","",""  {where internet is APN setting}
   delay(5000);
   ShowSerialData();

#ifdef LOG_PRINT
   Serial.println("2SIM: AT+CIICR");
#endif
 
   mySerial.println("AT+CIICR");//bring up wireless connection
   delay(1000);
   ShowSerialData();

#ifdef LOG_PRINT
    Serial.println("2SIM: AT+CIFSR");
#endif

   mySerial.println("AT+CIFSR");//get local IP adress
   delay(1000);
   ShowSerialData();  
   delay(1000);

#ifdef LOG_PRINT
    Serial.println("2SIM: AT+CIPSTART");
#endif
   mySerial.println("AT+CIPSTART=\"TCP\",\"184.106.153.149\",\"80\""); //start up the connection,where 184.106.153.149 is IP address of ThingSpeak & port no 80
   delay(5000);
   ShowSerialData();
  // Let's begin to send data to remote server
     int a=sizeof(X);
     int value=43+a;
#ifdef LOG_PRINT
     Serial.println("2SIM: AT+CIPSEND=");
 #endif
 
    mySerial.print("AT+CIPSEND=");
    mySerial.println(value);
    delay(1000);
    ShowSerialData();
    mySerial.print(Y);//begin send data to remote server
    mySerial.println(X);
    delay(1500);
    ShowSerialData();
    delay(2500);

#ifdef LOG_PRINT
     Serial.println("2SIM: AT+CIPSHUT");
#endif
    mySerial.println("AT+CIPSHUT");
    delay(1500);
    ShowSerialData();
     delay(1000);
    //delay(2*oneSecond);
}

void ShowSerialData()
{
  while(mySerial.available()!=0)
    Serial.write(mySerial.read());
}
