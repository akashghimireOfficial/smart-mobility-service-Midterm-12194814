#include "ros/ros.h"
#include "project/GPSWEATHER.h"
#include <cstdio>
#include <string>
#include <iostream>

bool send_weather(project::GPSWEATHER::Request &req,
                      project::GPSWEATHER::Response &res)
{
  std::string location=req.location;
  if (location=="q"){
    return false;
  }
  else{
    res.weather="Hot"; //Just Assumption
    return true;
  }

  
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "GPS_WEATHER_server_node");

  ros::NodeHandle node_handle;

  ros::ServiceServer service = node_handle.advertiseService("GPS_WEATHER", send_weather);

  ROS_INFO("GPS_WEATHER Running...");

  ros::spin();

  return 0;
}
