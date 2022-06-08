#include <ros/ros.h>
#include <temp_converter_ros_pkg/Celsius2Fahrenheit.h>

bool convert(temp_converter_ros_pkg::Celsius2Fahrenheit::Request &req,
             temp_converter_ros_pkg::Celsius2Fahrenheit::Response &res)
{
    res.temp_Fahrenheit = (1.8 * req.temp_Celsius) + 32;
    ROS_INFO("request: temp_Celsius=%f", (double) req.temp_Celsius);
    ROS_INFO("sending back response: temp_Fahrenheit=%f", (double)res.temp_Fahrenheit);
    
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Celsius2FahrenheitServer");
    
    ros::NodeHandle nodeHandle;
    ros::ServiceServer service = nodeHandle.advertiseService("Celsius2Fahrenheit", convert);
    ROS_INFO("Ready to convert Celsius into Fahrenheit");
    ros::spin();
    
    return 0;
}