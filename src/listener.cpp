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
#include "beginner_tutorials/Level.h"

// global variable
int listener_count = 0;

// A function receive messages over the ROS system
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
	// post ROS_INFO
	ROS_INFO("I heard from talker: [%s]", msg->data.c_str());

	//increment listener_count
	listener_count ++;
}

int main(int argc, char **argv) {
	// Initialize ROS node listener
	ros::init(argc, argv, "listener");

	// Create nodehandle
	ros::NodeHandle n;

	// Create a client object for log_level service
	ros::ServiceClient logClient = n.serviceClient<beginner_tutorials::Level>("log_level");
	beginner_tutorials::Level::Request req;
	beginner_tutorials::Level::Response resp;

	// set up value for req
	req.count = listener_count;

	// actually call the service
	bool success = logClient.call(req, resp);

	if (success) {
		ROS_INFO_STREAM(resp.message);
	} else {
		ROS_ERROR_STREAM("Failed to call log_level");
	}

	// subscribe topic std_msgs/String
	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

	// Pump callbacks using ros::spin()
	ros::spin();

	return 0;
}



