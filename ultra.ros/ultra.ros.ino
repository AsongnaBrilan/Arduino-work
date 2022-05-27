/*
 * program written to publish potentiometer readings
 * and a subcriber subscribes to the topic.
 */

#include <ros.h>
#include <std_msgs/Float32.h>

ros::NodeHandle nh;
std_msgs::Float32 dist_msg;
ros::Publisher dist_values("RADAR", &dist_msg);

// declaring of potentiometer varaibles

#define trig_pin 4
#define echo_pin 5

float duration = 0;
float object_dist = 0;

void setup()
{
  Serial.begin(9600);
  nh.initNode();
  nh.advertise(dist_values);
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  digitalWrite(echo_pin, LOW);
  digitalWrite(trig_pin, LOW);
  
}


float meas_obj_dist()
{
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo_pin, HIGH);
  // Calculating the distance
  
  object_dist = duration * 0.034 / 2;   // this distance is in cm
  object_dist = object_dist/100;  // distance in m
  
  //int object_dist_round = round(object_dist);  // this rounds the decimals up to integer values.

  return object_dist;
}

void loop()
{
  dist_msg.data = meas_obj_dist();
  dist_values.publish(&dist_msg);
  delay(10);
  nh.spinOnce();
}
