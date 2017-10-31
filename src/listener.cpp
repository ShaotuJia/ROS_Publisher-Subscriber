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
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
	// post ROS_INFO
	ROS_INFO("I heard from talker: [%s]", msg->data.c_str());
}

int main(int argc, char **argv) {
	// Initialize ROS node listener
	ros::init(argc, argv, "listener");

	// Create nodehandle
	ros::NodeHandle n;

	// subscribe topic std_msgs/String
	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

	// Pump callbacks using ros::spin()
	ros::spin();

	return 0;
}



