/*
 * this program is written to measure 
 * the ambient temp of a room using 
 * the TMP102 temp sensor
 * 
 * the program will be in standby mode for now.
 */

#include <ros.h>
#include <Wire.h>
#include <std_msgs/Float32.h>

//setup the ros node and publisher
std_msgs::Float32 temp_msg;
ros::Publisher pub_temp("temperature", &temp_msg);
ros::NodeHandle nh;

int sensorAddress = 0x91 >> 1;

void setup()
{
  Wire.begin();
  nh.initNode();
  nh.advertise(pub_temp);
  
}

long publisher_time;

void loop()
{
  if (millis() > publisher_time)
  {
    Wire.requestFrom(sensorAddress, 2);
    delay(10);
    if (2 <= Wire.available())
    {
      byte msb;
      byte lsb;
      int temperature;
      msb = Wire.read();
      lsb = Wire.read();
      temperature = ((msb) << 4);
      temperature |= (lsb >> 4);
      temp_msg.data = temperature*0.0625;  // temp sensor resolution

      pub_temp.publish(&temp_msg);
      
    }

    publisher_time = millis() + 1000;  //publishes once a second
  }

  nh.spinOnce();
}
