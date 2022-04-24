#include "ros/ros.h"
#include <string>
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"

using namespace std;
#include <sstream>

float SPEED_LIMIT; 
int32_t Plate_number=123;

ros::Publisher speed_limiter;


void subCallback(const std_msgs::Float32::ConstPtr& speed)
{

  ros::NodeHandle callback_node_handle;

  if (callback_node_handle.getParam("speed_limit", SPEED_LIMIT))
  {
    std_msgs::Int32 plt_num;
    plt_num.data = Plate_number; 
    //to echo plate number
    
    
    
    //publishing
    if (speed->data>= SPEED_LIMIT){
       printf("Ok \n");
       
       speed_limiter.publish(plt_num);
    
    }

    
  }
  else
  {
    ROS_WARN("No value set for speed_limit parameter.");
  }


}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "speed_limiter_node");

  ros::NodeHandle node_handle;

  speed_limiter = node_handle.advertise<std_msgs::Int32>("speed_limiter", 10);

  ros::Subscriber speed_sub = node_handle.subscribe("speed", 10, subCallback);

  ros::spin();

  return 0;
}
