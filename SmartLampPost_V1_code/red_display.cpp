/* Insert file library */
#include   <SPI.h>
#include   <DMD.h>
#include   <TimerOne.h>
#include   <SystemFont5x7.h>     
#include   "red_display.h"
#include   "temp_hum.h"
//#include <DS3231.h>

 
#define Panjang 2                        // Number of length of Display P10
#define Lebar   1                        // Number of width of Display P10
//#define sensor A5                         // Define sensor pin = pin A5
//DS3231 rtc(SDA, SCL);
DMD dmd(Panjang, Lebar);                  // Length x Width
/* Deklarasi Variable */
float suhu;
float yoyo;
//int yin;
//int yang;
char chr[5];
static void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}
 
void red_display_setup(void)
{
  Serial.println("red_display_setup()");
 // Setup DMD
 Timer1.initialize( 5000 );           
 Timer1.attachInterrupt( ScanDMD );
 dmd.selectFont(SystemFont5x7);           // Font used
 dmd.clearScreen( true );
 Serial.begin(9600);                      // Activate function of communication serial   
}
 
void red_display_loop(void)
{
  dmd.clearScreen( true );
  suhu=get_temperature();
  yoyo=get_humidity();
  Serial.println(suhu);
  dtostrf(suhu, 4, 2, chr);
  dmd.drawString( 2, 0, "Temp=", 5, GRAPHICS_NORMAL );
  dtostrf(suhu, 4, 2, chr);
  dmd.drawString( 33, 0, chr, 5, GRAPHICS_NORMAL );
  Serial.println(yoyo);
  dtostrf(suhu, 4, 2, chr);
  dmd.drawString( 2, 9, "Humd=", 5, GRAPHICS_NORMAL );
  dtostrf(yoyo, 4, 2, chr);
  dmd.drawString( 33, 9, chr, 5, GRAPHICS_NORMAL );
  delay(10000);//10 sec
   
}
