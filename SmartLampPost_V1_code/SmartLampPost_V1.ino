

//#define RTC_READ
#define SENSE_DATA_UPLOAD  1
#define TEMP_DISPLAY  1
#define LED_OUTPUT  1

#ifdef SENSE_DATA_UPLOAD
#include "sense_upload_service.h"
#endif

#ifdef RTC_READ
#include "rtc.h"
#endif

#ifdef TEMP_DISPLAY
#include "red_display.h"
#endif

#ifdef LED_OUTPUT
  #include "led_output.h"
  #include "vi_sense.h"

  #define   THRESHOLD_DAY_LOW      4
  #define   THRESHOLD_NIGHT_HIGH   4.5
#endif




unsigned long int loop_count = 0;

// All timings expressed in seconds. 
#define LOOP_TIME             10         // 10 s
#define DATA_UPLOAD_TIME      15*60        // 
#define TEMP_DISPLAY_TIME     15*60        //10s
#define RTC_READ_TIME         10*60

const unsigned short int DATA_UPLOAD_COUNT =  DATA_UPLOAD_TIME/LOOP_TIME;
const unsigned short int TEMP_DISPLAY_TIME_COUNT = TEMP_DISPLAY_TIME/LOOP_TIME;
const unsigned RTC_READ_COUNT =   RTC_READ_TIME/LOOP_TIME;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

#ifdef TEMP_DISPLAY
  red_display_setup();
#endif

#ifdef SENSE_DATA_UPLOAD
  sense_upload_setup();
#endif

#ifdef LED_OUTPUT
  led_setup();
#endif
  Serial.println("Counts: ");
  Serial.print(DATA_UPLOAD_COUNT);
  Serial.println(" ");
  Serial.println(TEMP_DISPLAY_TIME_COUNT);
  

}


void loop() {

  Serial.print("Loop: ");
  Serial.println(loop_count);

#ifdef LED_OUTPUT
  float solar_voltage = Solar_Voltage(); 
  if (solar_voltage > THRESHOLD_NIGHT_HIGH)
  {
      led_turn_off();
      Serial.print("LED_turned_OFF");
  }
  else if (solar_voltage < THRESHOLD_DAY_LOW)
  {
      led_turn_on();
      Serial.print("LED_turned_ON");
  }
#endif
  
  
#ifdef TEMP_DISPLAY
  if (loop_count % TEMP_DISPLAY_TIME_COUNT == 0)
    red_display_loop();
#endif

#ifdef RTC_READ
  if (loop_count % RTC_READ_COUNT == 0)
  {
    rtc_loop();
  }
#endif

#ifdef SENSE_DATA_UPLOAD
  if (loop_count % DATA_UPLOAD_COUNT == 0)
    sense_upload_loop();
#endif


  loop_count++;
  if (loop_count<=180)
      delay(1000);
  else
      delay(LOOP_TIME*1000);
}
