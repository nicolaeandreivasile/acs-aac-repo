#include <ros/ros.h>
#include <temp_converter_ros_pkg/Fahrenheit2Kelvin.h>

bool convert(temp_converter_ros_pkg::Fahrenheit2Kelvin::Request &req,
             temp_converter_ros_pkg::Fahrenheit2Kelvin::Response &res)
{
    res.temp_Kelvin = ((req.temp_Fahrenheit - 32) / 1.8) + 275.15;
    ROS_INFO("request: temp_Fahrenheit=%f", (double) req.temp_Fahrenheit);
    ROS_INFO("sending back response: temp_Kelvin=%f", (double) res.temp_Kelvin);
    
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Fahrenheit2KelvinServer");
    
    ros::NodeHandle nodeHandle;
    ros::ServiceServer service = nodeHandle.advertiseService("Fahrenheit2Kelvin", convert);
    ROS_INFO("Ready to convert Fahrenheit into Kelvin");
    ros::spin();
    
    return 0;
}