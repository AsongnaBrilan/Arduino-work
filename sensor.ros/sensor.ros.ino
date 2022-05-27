/*
 * code written to compute all LEVON's sensor input data using a single arduino
 * The code is event driven especially the US sensors
 */


#include <NewPing.h>

#define trig_pin_0 9
#define echo_pin_0 9
int us_time_0 = millis();

#define trig_pin_1 10
#define echo_pin_1 10
int us_time_1 = millis();

#define trig_pin_2 11
#define echo_pin_2 11
int us_time_2 = millis();

#define max_dist 400
NewPing us0(trig_pin_0, echo_pin_0, max_dist);
NewPing us1(trig_pin_1, echo_pin_1, max_dist);
NewPing us2(trig_pin_2, echo_pin_2, max_dist);

float dist_0, dist_1, dist_2;

// flashinf lEDs for  testing

int led_1 = 8;
int led_2 = 7;
int led_3 = 6;

void setup()
{
  Serial.begin(115200);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
}

void loop()
{

  if (millis() - us_time_0 <= 1000)
  {
    dist_0 = us0.ping_cm();
    Serial.print(dist_0);
    Serial.print("cm\t    ");
    digitalWrite(led_1, HIGH);
    us_time_0 = millis();
  }
  else
  {
    digitalWrite(led_1, LOW);
  }
  
  if (millis() - us_time_1 > 1000 && millis() - us_time_1 < 2000 )
  {
    dist_1 = us1.ping_cm();
    Serial.print(dist_1);
    Serial.print("cm\t    ");
    digitalWrite(led_2, HIGH);
    us_time_1 = millis();
  }
  else
  {
    digitalWrite(led_2, LOW);
  }

  if (millis() - us_time_2 >= 3000)
  {
    dist_2 = us2.ping_cm();
    Serial.print(dist_2);
    Serial.print("cm\t    ");
    digitalWrite(led_3, HIGH);
    us_time_2 = millis();
  }
  else
  {
    digitalWrite(led_3, LOW);
  }

  Serial.println("\n");
  
}
