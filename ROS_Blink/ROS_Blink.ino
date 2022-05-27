#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>

#define BUTTON 8
#define LED 13


/*
 * issues that may arise:
 * change in the msg.h file cstring to string.h and std::memcpy() to memcpy()
 * Running rosserial we do: rosrun rosserial_python serial_node.py /dev/tty<USB# or ACM#>, in terminal
 * after running roscore.
 * To see arduino port connection we do: dmesg|grep tty
 * Running topic to read published data we do:  rostopic echo button_press
 * Running topic to publishe data we do: rostopic pub toggle_led std_msgs/UInt16 "data: 0"
 */
 
ros::NodeHandle node_handle;

std_msgs::String button_msg;
std_msgs::UInt16 led_msg;

void subscriberCallback(const std_msgs::UInt16 & led_msg)
{
  if (led_msg.data == 1)
  {
    digitalWrite(LED, HIGH);
  }else
  {
    digitalWrite(LED, LOW);
  }
}

ros::Publisher button_publisher("button_press", &button_msg);
ros::Subscriber<std_msgs::UInt16> led_subscriber("toggle_led", &subscriberCallback);


void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);

  node_handle.initNode();
  node_handle.advertise(button_publisher);
  node_handle.subscribe(led_subscriber);
}

void loop()
{
  if (digitalRead(BUTTON) == HIGH)
  {
    button_msg.data = "Pressed";
  }
  else
  {
    button_msg.data = "Not pressed";
  }

  button_publisher.publish(&button_msg);
  node_handle.spinOnce();

  delay(100);

}
