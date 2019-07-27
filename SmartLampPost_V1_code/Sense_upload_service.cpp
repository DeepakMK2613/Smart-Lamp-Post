
#include "sense_upload_service.h"
#include "temp_hum.h"
#include "vi_sense.h"
#include "TimerOne.h"
#include "thingspeak.h"

void sense_upload_setup() {

  thingsSpeakGsmSetup();
  thingsSpeakSetPrivateSendKey("HZGMTC53I4KG2FZP");
}


static unsigned short int dataUploadCount = 0;

 void sense_upload_loop() {

  float temperature=get_temperature();
  float humidity=get_humidity();

  float bat_I = Battery_Ampere();
  float bat_V = Battery_Voltage();
  float sol_V = Solar_Voltage();
  float sol_I = Solar_Ampere();  
 
  Serial.print("Parameters: ");
  Serial.print(temperature);
  Serial.print(" ");
  Serial.print(humidity);
  Serial.print(" ");
  Serial.print(sol_V);
  Serial.print(" ");
  Serial.print(sol_I);
  
  Serial.print(" ");
  Serial.print(bat_I);
  Serial.print(" ");
  Serial.println(bat_V);
  
  
  float parameters[6] = { temperature, humidity, sol_V, sol_I, bat_V, bat_I};

  Serial.print("dataUploadCount: ");
  Serial.println(dataUploadCount);
  dataUploadCount++;
  thingsSpeakSend(parameters,  6);
  delay(30000);

 
}
