/*
 * logging is the process of reocording either events occuring in 
 * OS or other software runs, or messages between different users of
 * a communication software. Infact it the act of keeping a log.
 */

#include <ros.h>

ros::NodeHandle nh;

void setup()
{
  nh.initNode();
}

void loop()
{
  //wait until we are actually connected
  while (!nh.connected())
  {
    nh.spinOnce();
  }

  nh.logdebug("Debug Statement");
  nh.loginfo("Program info");
  nh.logwarn("Warnings");
  nh.logerror("Errors..");
  nh.logfatal("Fatalities!");
  delay(5000);
  
}
