
#include "sense_upload_service.h"
#include "temp_hum.h"
#include "vi_sense.h"
#include "TimerOne.h"
#include "send2thinkspeak.h"

#include <SoftwareSerial.h>
#include<String.h>
#include<math.h>
 const long oneSecond=1000;//a second is thousand millisecond.
 const long oneMinute=oneSecond*60;
 const long oneHour=oneMinute*60;
 unsigned long counter;
SoftwareSerial mySerial(3,4);
String length();
 
String data = "{\"Temp\":get_temperature(), \"Humidity\":get_humidity(), \"AirQ\":air_quality(), \"ldr\":LightIntensity()}";
void sense_upload_setup() {
  //Serial.begin(9600);
  mySerial.begin(9600);     
  Timer1.initialize(1000000);
//  Timer1.attachInterrupt(isr);

}

 void sense_upload_loop() {
      
      Serial.print("Temp=");
      Serial.println(get_temperature());
      Serial.print("Humid=");
      Serial.println(get_humidity());
      
      Serial.println("Send-Temperature");
      Send2thingspeak("GET /update?key=K9W27LYN5TIN8P83&field1=",get_temperature());
      delay(1000);
      Serial.println("Send-Humid");
      Send2thingspeak("GET /update?key=K9W27LYN5TIN8P83&field2=",get_humidity());
      delay(1000);
      Serial.print("Sol-Vol=");
      Serial.println(Solar_Voltage());
      Serial.print("\tSol-Amp=");
      Serial.println(Solar_Ampere());
      Serial.print("\tBatt-Vol=");
      Serial.println(Battery_Voltage());
      Serial.print("\tBatt-Amp=");
      Serial.println(Battery_Ampere());
      Serial.println();
      Serial.println();

     Serial.println("Send-SolarV");
     Send2thingspeak("GET /update?key=K9W27LYN5TIN8P83&field3=",Solar_Voltage());//https://api.thingspeak.com/update?api_key=DGQX2I3E3I65B5YJ&field1=0

     Serial.println("Send-SolarA");
     Send2thingspeak("GET /update?key=K9W27LYN5TIN8P83&field4=",Solar_Ampere());

     Serial.println("Send-BatteryV");
     Send2thingspeak("GET /update?key=K9W27LYN5TIN8P83&field5=",Battery_Voltage());

     Serial.println("Send-BatteryI");
     Send2thingspeak("GET /update?key=K9W27LYN5TIN8P83&field6=",Battery_Ampere());
     
     //Send2thingspeak("GET /update?key=DGQX2I3E3I65B5YJ&field1=",Solar_Voltage2());//https://api.thingspeak.com/update?api_key=DGQX2I3E3I65B5YJ&field1=0
    
     //Send2thingspeak("GET /update?key=DGQX2I3E3I65B5YJ&field2=",Solar_Ampere2());
   
     if (mySerial.available())
     Serial.write(mySerial.read());
     //delay(30*oneMinute);
}
