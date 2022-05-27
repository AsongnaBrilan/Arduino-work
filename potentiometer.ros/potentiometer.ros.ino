/*
 * program written to publish potentiometer readings
 * and a subcriber subscribes to the topic.
 */

#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle nh;
std_msgs::UInt16 potValues_msg;
ros::Publisher pot_values("potentiometer", &potValues_msg);

// declaring of potentiometer varaibles
#define pot_pin A0
int pot_reading = 0;

void setup()
{
  Serial.begin(9600);
  nh.initNode();
  nh.advertise(pot_values);
  pinMode(pot_pin, INPUT);
  
}

void loop()
{
  pot_reading = analogRead(pot_pin);
  //pot_reading = map(pot_reading, 0, 1023, 0, 255);
  
  Serial.println(pot_reading);
  
  potValues_msg.data = pot_reading;
  pot_values.publish(&potValues_msg);
  delay(10);
  nh.spinOnce();
}
