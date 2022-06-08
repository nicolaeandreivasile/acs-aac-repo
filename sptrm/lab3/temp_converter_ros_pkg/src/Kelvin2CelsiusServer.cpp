#include <ros/ros.h>
#include <temp_converter_ros_pkg/Kelvin2Celsius.h>

bool convert(temp_converter_ros_pkg::Kelvin2Celsius::Request &req,
             temp_converter_ros_pkg::Kelvin2Celsius::Response &res)
{
    res.temp_Celsius = req.temp_Kelvin - 273.15;
    ROS_INFO("request: temp_Kelvin=%f", (double) req.temp_Kelvin);
    ROS_INFO("sending back response: temp_Celsius=%f", (double) res.temp_Celsius);
    
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Kelvin2CelsiusServer");
    
    ros::NodeHandle nodeHandle;
    ros::ServiceServer service = nodeHandle.advertiseService("Kelvin2Celsius", convert);
    ROS_INFO("Ready to convert Kelvin into Celsius");
    ros::spin();
    
    return 0;
}