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
#include <memory>
#include <ros/ros.h>
#include <ros/topic.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include <tf/transform_listener.h>
#include "std_msgs/String.h"
#include "beginner_tutorials/Level.h"

std::shared_ptr<ros::NodeHandle> nh;

TEST(TESTTalker, log_level_Service ) {

	ros::service::waitForService("log_level");
	ros::ServiceClient logClient = nh->serviceClient<beginner_tutorials::Level>("log_level");
	bool exists(logClient.waitForExistence(ros::Duration(10)));
	EXPECT_TRUE(exists);
}


TEST(TestTalker, tf_transform) {
	  tf::TransformListener listener;

	  ros::Rate rate(10.0);
	  while (nh->ok()) {
	    tf::StampedTransform transform;
	    try{
	      listener.lookupTransform("world", "talk",
	                               ros::Time(0), transform);
	    }
	    catch (tf::TransformException ex){
	      ROS_ERROR("%s",ex.what());
	      ros::Duration(1.0).sleep();
	    }

	    EXPECT_EQ(transform.getOrigin().x(), 1.0);
	    EXPECT_EQ(transform.getOrigin().y(), 2.0);
	    EXPECT_EQ(transform.getOrigin().z(), 8.0);

	    rate.sleep();
	  }

}
int main(int argc, char **argv) {
  ros::init(argc, argv, "talker_test");
  nh.reset(new ros::NodeHandle);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
