/*
 * @file talk.cpp
 * @brief This is the publisher to send message to  topic std_msgs/string
 * and advertise service to change the base output string
 * @author Shaotu Jia
 * @copyright Copyright (C) 2007 Free Software Foundation, Inc.
 * @details GNU GENERAL PUBLIC LICENSE. Version 3, 29 June 2007
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_srvs/Trigger.h"
#include "std_srvs/Empty.h"

/**
 *@brief This is the callback function to response calling service
 *@param req The request to service with data-type std_srvs::Trigger
 *@param resp The response from service with data-type std_srvs::Trigger
 */

bool trigger(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& resp) {
	std_srvs::Trigger t;
	t.response.success = true;
	t.response.message = "You are triggering the talker_service";
	resp.success = t.response.success;
	resp.message = t.response.message;

	ROS_INFO("%s", t.response.message.c_str());
	return true;
}

int main(int argc, char **argv) {

	// Initialize node name "talker"
	ros::init(argc, argv, "talker");

	// Create NodeHandle n;
	ros::NodeHandle n;

	/**
	 * Register service talker_service at ROS master to response string
	 */
	ros::ServiceServer server = n.advertiseService("Talker_service", &trigger);


	/**
	 * Register the node as publisher at ROS master to topic std_msgs::String
	 * The topic name is "chatter" and queue size 1000
	 */
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

	// Set up the loop rate as 10Hz
	ros::Rate loop_rate(1);

	/**
	 * A count of how many messages we have sent. This is used to create
	 * a unique string for each message
	 */
	int count = 0;
	while (ros::ok()) {

		// This is a message object. You stuff it with data, and then publish it.
		std_msgs::String msg;

		std::stringstream ss;
		ss << "Hello from talker" << count;
		msg.data = ss.str();

		ROS_INFO("%s", msg.data.c_str());

		// Publish message
		chatter_pub.publish(msg);

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}

	return 0;
}
