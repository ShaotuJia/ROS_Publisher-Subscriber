# beginner_tutorials
[![Build Status](https://travis-ci.org/ShaotuJia/beginner_tutorials.svg?branch=master)](https://travis-ci.org/ShaotuJia/beginner_tutorials)
[![Coverage Status](https://coveralls.io/repos/github/ShaotuJia/beginner_tutorials/badge.svg?branch=master)](https://coveralls.io/github/ShaotuJia/beginner_tutorials?branch=master)
---
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
  git clone -b Week11_HW https://github.com/ShaotuJia/beginner_tutorials.git 
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
- all unit tests can be run by invoking the run_tests target
  ```
  catkin_make run_tests
  ```
- to get a summary of the unit test results as well as references to which tests contain errors or failed invoke
  ```
  catkin_test_results build/test_results
  ```
- run node talker, listener, and record topic chatter using launch file 
  ```
  roslaunch beginner_tutorials talker_listener.launch 
  ```
- run node talker and listener without recording topic chatter using launch file
  ```
  roslaunch beginner_tutorials talker_listener.launch baging:=0
  ```
- report the transform between any two frames broadcast over ROS.
  ```
  rosrun tf tf_echo world talk
  ```
- create a diagram of the frames being broadcast by tf over ROS.
  First, 
  ```
  rosrun tf view_frames
  ```
  then, 
  ```
  evince frames.pdf
  ```
- visualize the tree of frames being broadcast over ROS during runtime
  ```
  rosrun rqt_tf_tree rqt_tf_tree
  ```
- play back the bag file with the Listener node demonstration
  ```
  rosrun beginner_tutorials listener
  rosbag play chatter.bag
  ```
  

