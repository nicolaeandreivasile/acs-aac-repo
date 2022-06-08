#include <ros/ros.h>
#include <temp_converter_ros_pkg/Fahrenheit2Celsius.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Fahrenheit2CelsiusClient");
    if (argc != 2) {
        ROS_INFO("USAGE: Fahrenheit2CelsiusClient X");
        return 1;
    }

    ros::NodeHandle nodeHandle;
    ros::ServiceClient client = nodeHandle.serviceClient<temp_converter_ros_pkg::Fahrenheit2Celsius>("Fahrenheit2Celsius");
    temp_converter_ros_pkg::Fahrenheit2Celsius srv;
    srv.request.temp_Fahrenheit = atof(argv[1]);
    if (client.call(srv)) {
        ROS_INFO("temp_Celsius=%f", (double) srv.response.temp_Celsius);
    } else {
        ROS_INFO("Failed to call service Fahrenheit2Celsius");
        return 1;
    }

    return 0;
}