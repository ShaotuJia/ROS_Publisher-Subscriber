/*
 * @file listener.cpp
 * @brief This is the subscriber to receive message to  topic std_msgs/string
 * @author Shaotu Jia
 * @copyright Copyright (C) 2007 Free Software Foundation, Inc.
 * @details GNU GENERAL PUBLIC LICENSE. Version 3, 29 June 2007
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */

#include "ros/ros.h"
#include "std_msgs/String.h"

// A function receive messages over the ROS system
void chatterCallback(const std_msgs::String_::ConstPtr& msg) {

}
