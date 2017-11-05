# beginner_tutorials

## Overview
This tutorial is to familiarize how nodes communicate to others via topics. The talker is a node publishing message to topic std_msgs/string; the listener is a node subscribing message from topic std_msgs/string. 

## System Requirements
- Ubunut 16.04
- GitHub
- ROS Kinetic
- catkin
## Build/Run
- dependences: roscpp std_msgs

- clone repo to your catkin workspace: ~/catkin_ws/src
  ```
  git clone https://github.com/ShaotuJia/beginner_tutorials.git 
  ```
- build package
  ```
  catkin_make
  ```
- open three new temininals and source every opened terminal
  ```
  source beginner_tutorials/devel/setup.sh
  ```
- run node talker and listener from launch file
  ```
  roslaunch beginner_tutorials talker_listener.launch
  ```
- change the value of param Hz in talker_listener.launch to get different publishing frequency from node talker.e.g 
  ```
  <param name="Hz" value="20" />
  ```
- rosservice /Talker_service: return a string and bool to show that you are calling this service
  ```
  rosservice call /Talker_service
  ```
- rosservice /log_level: request count number to publish different logger_level by check whether count number is the muliple of 3, 5, 10, 20. e.g: count = 600
  ```
  roservice call /log_level "count: 600"
  ```
- shut down nodes by Ctrl + C when you want to 
