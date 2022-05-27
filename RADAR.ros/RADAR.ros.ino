/*
 * This program aims at using an array of ultrasonic sensors to build an obstacle detection
 * device which will play the role of a RADAR system.
 * 
 * Our code uses the newPing libary and it is event driven with no local delays.
 * 
 * The code appears to be a single node to ROS.
 * 
 * This project is under private control for a specific application. Any need for a copy, contact the author.
 * Developed by Asongna Brilan under LEVON technologies.
 */

///////////// A total of 12 US will be used //////////////////////


#include <ros.h>
#include <std_msgs/Float32.h>   // our RADAR will be sending floating point values.

ros::NodeHandle RADAR_node_msg;
std_msgs::Float32 radars_msg;

void setup()
{
  RADAR_node_msg.initNode();
  
}


void loop()
{
  
}









 
