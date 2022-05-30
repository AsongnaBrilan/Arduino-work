//Code Authors:
//* Ahmed A. Radwan (author)
//* Maisa Jazba

 #include <AFMotor.h>
#include <ArduinoHardware.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>


double w_r=0, w_l=0;

//wheel_rad is the wheel radius ,wheel_sep is
double wheel_rad = 0.0325, wheel_sep = 0.295;

ros::NodeHandle nh;

int lowSpeed = 200;
int highSpeed = 50;

double speed_ang=0, speed_lin=0;

int set_speed = 100;

AF_DCMotor motorDir_A(3);
AF_DCMotor motorDir_B(4);

void messageCb( const geometry_msgs::Twist& msg){
  speed_ang = msg.angular.z;
  speed_lin = msg.linear.x;
  w_r = (speed_lin/wheel_rad) + ((speed_ang*wheel_sep)/(2.0*wheel_rad));
  w_l = (speed_lin/wheel_rad) - ((speed_ang*wheel_sep)/(2.0*wheel_rad));
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &messageCb );

void Motors_init();
void MotorL(int Pulse_Width1);  // this is motorA
void MotorR(int Pulse_Width2);  // this is motorB

void setup(){
 Motors_init();
 nh.initNode();
 nh.subscribe(sub);
}

void loop(){
 MotorL(w_l*10);
 MotorR(w_r*10);
 nh.spinOnce();
}

void Motors_init(){
 motorDir_B.setSpeed(set_speed);
 motorDir_A.setSpeed(set_speed);
}

void MotorL(int Pulse_Width1){
 if (Pulse_Width1 > 0)
 {
     motorDir_A.run(FORWARD);
 }
 
 if (Pulse_Width1 < 0)
 {
     motorDir_A.run(BACKWARD);
 }
 
 if (Pulse_Width1 == 0){
     motorDir_A.run(RELEASE);
 }
}

void MotorR(int Pulse_Width2){
 if (Pulse_Width2 > 0){
     motorDir_B.run(FORWARD);
 }
 if (Pulse_Width2 < 0){
     motorDir_A.run(BACKWARD);
 }
 if (Pulse_Width2 == 0){
     motorDir_A.run(RELEASE);
 }
}
