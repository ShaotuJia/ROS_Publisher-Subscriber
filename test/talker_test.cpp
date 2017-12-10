/*
 * @file talker_test.cpp
 * @brief This rostest is to test the functions(service, publishing)
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
#include <tf/transform_listener.h>
#include "std_msgs/String.h"
#include "beginner_tutorials/Level.h"

// initialize a shared_ptr for NodeHandle for each test unit.
std::shared_ptr<ros::NodeHandle> nh;

/**
 * @brief This unit test is to check whether the log_level of node talker exists
 */
TEST(TESTTalker, log_level_Service ) {
	// waiting for service before executing following steps
	ros::service::waitForService("log_level");
	// create a client for service
	ros::ServiceClient logClient = nh->serviceClient<beginner_tutorials::Level>("log_level");
	// if the service exist within 10s, the varibale exists will be true, others will be false
	bool exists(logClient.waitForExistence(ros::Duration(10)));
	// check whether exists is true
	EXPECT_TRUE(exists);
}

TEST(TESTtf, transform) {

}

int main(int argc, char **argv) {
  ros::init(argc, argv, "talker_test");
  nh.reset(new ros::NodeHandle);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
