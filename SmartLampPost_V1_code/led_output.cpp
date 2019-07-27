
#include "led_output.h"
#include "Arduino.h"

//#define LED_CONTROL_WITH_PWM

static bool led_status;


#ifdef LED_CONTROL_WITH_PWM

#define LED_OUTPUT_PIN  10


void led_turn_on()
{
  Serial.println("led_turn_on()");
  led_status = HIGH;
  analogWrite(LED_OUTPUT_PIN, 0);

}
void led_turn_off()
{
  Serial.println("led_turn_off()");
  led_status = LOW;
  analogWrite(LED_OUTPUT_PIN, 255);
}
void led_setup()
{
  Serial.println("LED setup()");
  pinMode(LED_OUTPUT_PIN, OUTPUT);
  led_turn_off();

}
void led_toggle()
{
  if (led_status == LOW)
    led_turn_on();
  else
    led_turn_off();

}


#else


#define LED_OUTPUT_PIN  2

void led_turn_on()
{
  Serial.println("led_turn_on()");
  led_status = HIGH;
  digitalWrite(LED_OUTPUT_PIN, 0);

}
void led_turn_off()
{
  Serial.println("led_turn_off()");
  led_status = LOW;
  digitalWrite(LED_OUTPUT_PIN, 255);
}
void led_setup()
{
  Serial.println("LED setup()");
  pinMode(LED_OUTPUT_PIN, OUTPUT);
  led_turn_off();

}
void led_toggle()
{
  if (led_status == LOW)
    led_turn_on();
  else
    led_turn_off();

}
#endif
