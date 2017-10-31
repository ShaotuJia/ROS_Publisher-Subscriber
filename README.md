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
- start ROS master on one terminal
  ```
  roscore
  ```
- open node talker on one terminal
  ```
  rosrun beginner_tutorials talker
  ```
- open node listener on one terminal
  ```
  rosrun beginner_tutorials listener
  ```
- shut down nodes by Ctrl + C when you want to 
