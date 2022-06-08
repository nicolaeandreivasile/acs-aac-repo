#include <ros/ros.h>
#include <temp_converter_ros_pkg/Fahrenheit2Kelvin.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Fahrenheit2KelvinClient");
    if (argc != 2) {
        ROS_INFO("USAGE: Fahrenheit2KelvinClient X");
        return 1;
    }

    ros::NodeHandle nodeHandle;
    ros::ServiceClient client = nodeHandle.serviceClient<temp_converter_ros_pkg::Fahrenheit2Kelvin>("Fahrenheit2Kelvin");
    temp_converter_ros_pkg::Fahrenheit2Kelvin srv;
    srv.request.temp_Fahrenheit = atof(argv[1]);
    if (client.call(srv)) {
        ROS_INFO("temp_Kelvin=%f", (double) srv.response.temp_Kelvin);
    } else {
        ROS_INFO("Failed to call service Fahrenheit2Kelvin");
        return 1;
    }

    return 0;
}