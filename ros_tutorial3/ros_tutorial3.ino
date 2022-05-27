
/*
 * This is subcriber example
 * for blinking an LED on callback
 */

 #include <ros.h>
 #include <std_msgs/Empty.h>

 ros::NodeHandle nh;

 void messageCb (const std_msgs::Empty& toggle_msg)
 {
  digitalWrite(13, HIGH-digitalRead(13));  //blink the LED
 }

 ros::Subscriber<std_msgs::Empty> sub ("toggle_led", &messageCb);

 void setup()
 {
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
 }

 void loop()
 {
  nh.spinOnce();
  delay(3);
 }
