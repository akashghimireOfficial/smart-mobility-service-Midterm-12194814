#include "ros/ros.h"

#include "std_msgs/Float32.h"

const float SPEED = 60;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "speed_pub_node");

  ros::NodeHandle node_handle;

  ros::Publisher speed_pub = node_handle.advertise<std_msgs::Float32>("speed", 10);

  ros::Rate pub_rate(10);

  ROS_INFO("Publishing SPEED...");

  while(ros::ok())
  {

    std_msgs::Float32 msg;

    msg.data = SPEED;

    speed_pub.publish(msg);

    pub_rate.sleep();
  }

}
