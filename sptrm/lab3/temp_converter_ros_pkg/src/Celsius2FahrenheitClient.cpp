#include <ros/ros.h>
#include <temp_converter_ros_pkg/Celsius2Fahrenheit.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Celsius2FahrenheitClient");
    if (argc != 2) {
        ROS_INFO("USAGE: Celsius2FahrenheitClient X");
        return 1;
    }

    ros::NodeHandle nodeHandle;
    ros::ServiceClient client = nodeHandle.serviceClient<temp_converter_ros_pkg::Celsius2Fahrenheit>("Celsius2Fahrenheit");
    temp_converter_ros_pkg::Celsius2Fahrenheit srv;
    srv.request.temp_Celsius = atof(argv[1]);
    if (client.call(srv)) {
        ROS_INFO("temp_Fahrenheit=%f", (double) srv.response.temp_Fahrenheit);
    } else {
        ROS_INFO("Failed to call service Celsius2Fahrenheit");
        return 1;
    }

    return 0;
}