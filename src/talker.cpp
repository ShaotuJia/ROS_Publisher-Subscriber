/*
 * @file talk.cpp
 * @brief This is the publisher to send message to  topic std_msgs/string
 * @author Shaotu Jia
 * @copyright Copyright (C) 2007 Free Software Foundation, Inc.
 * @details GNU GENERAL PUBLIC LICENSE. Version 3, 29 June 2007
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv) {

	// Initialize node name "talker"
	ros::init(argc, argv, "talker");

	// Create NodeHandle n;
	ros::NodeHandle n;

	/**
	 * Register the node as publisher at ROS master to topic std_msgs::String
	 * The topic name is "chatter" and queue size 1000
	 */
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

	// Set up the loop rate as 10Hz
	ros::Rate loop_rate(10);

	/**
	 * A count of how many messages we have sent. This is used to create
	 * a unique string for each message
	 */
	int count = 0;
	while (ros::ok()) {

		// This is a message object. You stuff it with data, and then publish it.
		std_msgs::String_ msg;

		std::stringstream ss;
		ss << "Hello from talker" << count;
		msg.data = ss.str();

		ROS_INFO("%s", msg.data.c_str());

		// Publish message
		chatter_pub.Publisher(msg);

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}

	return 0;
}
