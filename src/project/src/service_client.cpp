#include "ros/ros.h"
#include "project/GPSWEATHER.h"
#include <cstdio>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "GPS_WEATHER_client_node");

  ros::NodeHandle node_handle;

  ros::ServiceClient client = node_handle.serviceClient<project::GPSWEATHER>("GPS_WEATHER");

  project::GPSWEATHER GPS_WEATHER_srv;

  char location[20];

  std::cout << "Type 'q' to quit" << std::endl;

  while (ros::ok())
  {
    std::cout << "Enter a location: ";
    std::cin >> location;

    GPS_WEATHER_srv.request.location = location;

    if (location =="q")
    {
      ROS_INFO("Exiting Application...");
      return 0;
    }

    if (client.call(GPS_WEATHER_srv))
    {
      std::string resp;
      resp = GPS_WEATHER_srv.response.weather;

      std::cout << "The weather is " << resp << std::endl;
    }
    else
    {
      ROS_ERROR("Service Call Failed");
      return 1;
    }

    std::cin.clear();


  }
}
