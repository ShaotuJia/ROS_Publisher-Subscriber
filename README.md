# beginner_tutorials

## Overview
This Week11 assignment adds additional features in last week assignment to familiarize tf package, rostest, and rosbag. The Talker node to broadcast a tf frame called /talk with parent /world. The tf tree has been viewed and saved as PDF. Gtest/rostest has been used to test the published tf transform and log_leve service. The topic chatter has been recorded using rosbag for 15s. And Listener node can receive the message from the rosbag record. 
## System Requirements
- Ubunut 16.04
- GitHub
- ROS Kinetic
- catkin
## Build/Run
- dependences: roscpp, std_msgs, message_generation

- clone repo to your catkin workspace: ~/catkin_ws/src
  ```
  git clone https://github.com/ShaotuJia/beginner_tutorials.git 
  ```
- build package
  ```
  catkin_make
  ```
- open three new temininals and source every opened termininal
  ```
  source beginner_tutorials/devel/setup.bash
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
  rosservice call /log_level "count: 600"
  ```
- shut down nodes by Ctrl + C when you want to 
### Week_11
- run node talker, listener, and record topic chatter using launch file 
  ```
  roslaunch beginner_tutorials talker_listener.launch 
  ```
- run node talker and listener without recording topic chatter using launch file
  ```
  roslaunch beginner_tutorials talker_listener.launch baging:=0
  ```

