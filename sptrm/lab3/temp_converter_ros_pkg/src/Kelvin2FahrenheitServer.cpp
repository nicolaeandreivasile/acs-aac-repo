#include <ros/ros.h>
#include <temp_converter_ros_pkg/Kelvin2Fahrenheit.h>

bool convert(temp_converter_ros_pkg::Kelvin2Fahrenheit::Request &req,
             temp_converter_ros_pkg::Kelvin2Fahrenheit::Response &res)
{
    res.temp_Fahrenheit = (1.8 * (req.temp_Kelvin - 273.15)) + 32;
    ROS_INFO("request: temp_Kelvin=%f", (double) req.temp_Kelvin);
    ROS_INFO("sending back response: temp_Fahrenheit=%f", (double) res.temp_Fahrenheit);
    
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Kelvin2FahrenheitServer");
    
    ros::NodeHandle nodeHandle;
    ros::ServiceServer service = nodeHandle.advertiseService("Kelvin2Fahrenheit", convert);
    ROS_INFO("Ready to convert Kelvin into Fahrenheit");
    ros::spin();
    
    return 0;
}