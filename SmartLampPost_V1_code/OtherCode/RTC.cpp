//#include <DS3232RTC.h>



//#include <Wire.h>
//#include <Time.h>
#include <DS3231.h>
#include "rtc.h"
DS3231 rtc(SDA, SCL);
void rtc_setup() {
  // put your setup code here, to run once:
  // Setup Serial connection
  //Serial.begin(9600);//115200
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  
  // Initialize the rtc object
 rtc.begin();

  // The following lines can be uncommented to set the date and time
 rtc.setDOW(FRIDAY);     // Set Day-of-Week to SUNDAY
 rtc.setTime(10, 25, 00);     // Set the time to 12:00:00 (24hr format)
 rtc.setDate(21, 06, 2019);   // Set the date to January 1st, 2014
  
}

void rtc_loop() {
  // put your main code here, to run repeatedly:
//Serial.print(rtc.getDOWStr());
//Serial.print(" ");

  // print
  Serial.println("RTC: loop");
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  // Send time
  Serial.println(rtc.getTimeStr());
  
}
