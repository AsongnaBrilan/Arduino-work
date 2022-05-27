# SensorFusion sensors for **LEVON**

## Description
 SensorFusion is the act of combining multilpe working sensors in other to achieve a goal. The data published by each of our sensors have to be used, related to others to build a powerful perception algorithm for the control of our vehicle all using arduino.

**GPS sensor** 
# Handled by Arduino (1)
 Used to know the exact location and position of our system in the map.
 
**IMU (6 or 9 DOF)**
# Handled by Arduino (2)
 Used to measure variables such as acceleration, rotation, magnetic fields and ambient temperature of our system. This will be intensively used to calibrate our vehicle.
 
**Ultrasonic sensors. used here as radars**
# Handled by Arduino (3)
 This is a hand built local Radar unit for our system, and it will be used for object detection using SONAR waves. Its plays a major rule in the navigation of our system in its environment.
 
**clock.** 
# Handled by Arduino (4)
 Used to get real time clock data for effective control.
 
**LDR.**
# Handled by Arduino (4)

**Camera.**
# Handled by Raspberry pi4B

**Encoders.**
# Handled by Arduino (5)

############# Aduino 4 is a general arduino which operates data from multiple sensors with less weight.
############# All the arduinos above publish thier data to the ROS.



