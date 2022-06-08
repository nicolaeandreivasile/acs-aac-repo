#include <ros/ros.h>
#include <temp_converter_ros_pkg/Celsius2Kelvin.h>

bool convert(temp_converter_ros_pkg::Celsius2Kelvin::Request &req,
             temp_converter_ros_pkg::Celsius2Kelvin::Response &res)
{
    res.temp_Kelvin = req.temp_Celsius + 273.15;
    ROS_INFO("request: temp_Celsius=%f", (double) req.temp_Celsius);
    ROS_INFO("sending back response: temp_Kelvin=%f", (double)res.temp_Kelvin);
    
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Celsius2KelvinServer");
    
    ros::NodeHandle nodeHandle;
    ros::ServiceServer service = nodeHandle.advertiseService("Celsius2Kelvin", convert);
    ROS_INFO("Ready to convert Celsius into Kelvin");
    ros::spin();
    
    return 0;
}