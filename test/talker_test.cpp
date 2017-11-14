/*
 * @file talker_test.cpp
 * @brief This rostest is to test service, and TF broadcast
 * in node talker
 * @author Shaotu Jia
 * @copyright Copyright (C) 2007 Free Software Foundation, Inc.
 * @details GNU GENERAL PUBLIC LICENSE. Version 3, 29 June 2007
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */
#include <ros/ros.h>
#include <ros/topic.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include "std_msgs/String.h"
#include "beginner_tutorials/Level.h"



TEST(TESTTalker, log_level_Service ) {
	std::shared_ptr<ros::NodeHandle> nh;
	ros::ServiceClient logClient = nh->serviceClient<beginner_tutorials::Level>("log_level");
	bool exists(logClient.waitForExistence(ros::Duration(1)));
	EXPECT_TRUE(exists);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "talker_test");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
