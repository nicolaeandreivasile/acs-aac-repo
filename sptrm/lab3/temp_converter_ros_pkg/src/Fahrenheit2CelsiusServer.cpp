#include <ros/ros.h>
#include <temp_converter_ros_pkg/Fahrenheit2Celsius.h>

bool convert(temp_converter_ros_pkg::Fahrenheit2Celsius::Request &req,
             temp_converter_ros_pkg::Fahrenheit2Celsius::Response &res)
{
    res.temp_Celsius = (req.temp_Fahrenheit - 32) / 1.8;
    ROS_INFO("request: temp_Fahrenheit=%f", (double) req.temp_Fahrenheit);
    ROS_INFO("sending back response: temp_Celsius=%f", (double) res.temp_Celsius);
    
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Fahrenheit2CelsiusServer");
    
    ros::NodeHandle nodeHandle;
    ros::ServiceServer service = nodeHandle.advertiseService("Fahrenheit2Celsius", convert);
    ROS_INFO("Ready to convert Fahrenheit into Celsius");
    ros::spin();
    
    return 0;
}