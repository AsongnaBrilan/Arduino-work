
#include <NewPing.h>

#define trig_pin_0 9
#define echo_pin_0 9

#define trig_pin_1 10
#define echo_pin_1 10

#define trig_pin_2 11
#define echo_pin_2 11

#define max_dist 400
NewPing us0(trig_pin_0, echo_pin_0, max_dist);
NewPing us1(trig_pin_1, echo_pin_1, max_dist);
NewPing us2(trig_pin_2, echo_pin_2, max_dist);

float dist_0, dist_1, dist_2;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  dist_0 = us0.ping_cm();
  delay(5);
  Serial.print(dist_0);
  Serial.print("cm\t    ");

  dist_1 = us1.ping_cm();
  delay(5);
  Serial.print(dist_1);
  Serial.print("cm\t    ");

  dist_2 = us2.ping_cm();
  delay(5);
  Serial.print(dist_2);
  Serial.println("cm\t    ");
}
