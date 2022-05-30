/*
 * General program(node) to control all LEVONS actuations.
 * This includes controlling and monitoring all output variables.
 * One of the objective of this node is to make it event
 * driven and to use less libaries as possible.
 * This programs appears to ROS as a node.
 * The major output variables are:
 * 
 * /////////////////////////////// MOTORS.. //////////////////////
 * /////////////////////////////// LAMPS  //////////////////////
 * /////////////////////////////// SERVOS.. //////////////////////
 * /////////////////////////////// RGBs   //////////////////////
 * /////////////////////////////// BUZZER.. //////////////////////
 * 
 * A shift register will be used to control the lamps.
 * Note that the motor driver used here was the L293D,
 * this could be replaced with others making sure you understand 
 * the motors architecture.
 * 
 * ////////////////////////////// STEERING ANGLE DATA FOR LEVON100 ///////////////////////////
 * 
 * MIN_A = 25
 * MAX_A = 100
 * 
 * MIN_B = 20;
 * MAX_B = 140;
 * 
 * Program written by Asongna Brilan Nso N. Property of LEVON.
 */

////////////// required libaries //////////////
#include <ros.h>
#include <AFMotor.h>  // libary to control motors. Just for testing.
#include <Servo.h>

// servo motors for steering.
Servo steeringDir_A;
Servo steeringDir_B;

int steeringAng_A = 0;  //variable to hold the required steering angles.
int steeringAng_B = 0;  // ranges from 0 - 140 degrees

int set_speed = 100;  //using the  L293D, the min set_speed should be 100

//int pos = 20; // for testing the functionality of the servos

// buzzer for communication
#define buzz 5

////////////////////////////////// motors ////////////////////////////////
AF_DCMotor motorDir_A(3);
AF_DCMotor motorDir_B(4);

////////////////////////////////// LAMPS ////////////////////////////////

////////////////////////////////// RGB  /////////////////////////////////

/////////////////////////////////// void setup //////////////////////////
void setup()
{
  Serial.begin(9600);
  steeringDir_A.attach(9);  // digital PMW pin ports for either arduino UNo, NANO or MEGA
  steeringDir_B.attach(10);

  //turning on motors
  motorDir_B.setSpeed(set_speed);
  motorDir_A.setSpeed(set_speed);
}

////////////////////////////////// void loop ///////////////////////////
void loop()
{
  steering_B_test();
  steering_A_test();
}

void steering_A_test()
{
  for (steeringAng_A = 25; steeringAng_A <= 100; steeringAng_A++)
  {
    steeringDir_A.write(steeringAng_A);
    delay(5);
  }

  for (steeringAng_A = 100; steeringAng_A >= 25; steeringAng_A--)
  {
    steeringDir_A.write(steeringAng_A);
    delay(5);
  }

  motorDir_A.run(FORWARD);
}

void steering_B_test()
{
  //steeringDir_B.write(steeringAng_B);
  
  for (steeringAng_B=50; steeringAng_B <= 150; steeringAng_B++)
  {
    steeringDir_B.write(steeringAng_B);
    delay(5);
  }

  for (steeringAng_B=150; steeringAng_B >= 50; steeringAng_B--)
  {
    steeringDir_B.write(steeringAng_B);
    delay(5);
  }

  motorDir_B.run(FORWARD);
}
