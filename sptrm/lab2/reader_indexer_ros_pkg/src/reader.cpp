#include <ros/ros.h>
#include <std_msgs/String.h>

#include <fstream>


int main(int argc, char **argv)
{
    if (argc < 2) {
        ROS_INFO("%s", "USAGE: rosrun reader_indexer_ros_pkg reader <input_file>");
        return 1;
    }

    ros::init(argc, argv, "reader");
    ros::NodeHandle nodeHandle;
    ros::Publisher readerPublisher = nodeHandle.advertise<std_msgs::String>("reader", 100);
    ros::Rate loopRate(10);

    std::ifstream inFile(argv[1]);
    std::string line;

    if (!inFile.is_open()) {
        ROS_INFO("%s", "File could not be opened");
        return 1;
    }

    while (ros::ok()) {
        std_msgs::String message;

        if (std::getline(inFile, line)) {
            message.data = line;
            ROS_INFO("%s", message.data.c_str());
            readerPublisher.publish(message);
        }
        
        ros::spinOnce();
        loopRate.sleep();
    }

    return 0;
}