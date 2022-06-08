#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include <stdlib.h>
#include <queue>

int main(int argc, char **argv) {
    ros::init(argc, argv, "random_husky_commands");

    ros::NodeHandle nh;
    ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("husky_velocity_controller/cmd_vel", 100);
    ros::Rate rate(1);

    std::queue<std::tuple<float, float, float>> tupleQueue;
    tupleQueue.push(std::tuple<float, float, float>{1, 0, 0});
    tupleQueue.push(std::tuple<float, float, float>{0, 0, 1.57});

    while(ros::ok()) {
        std::tuple<float, float, float> tupleCoord = (std::tuple<float, float, float>) tupleQueue.front();
        tupleQueue.pop();
        geometry_msgs::Twist msg;
        msg.linear.x=std::get<0>(tupleCoord);
        msg.linear.y=std::get<1>(tupleCoord);
        msg.angular.z=std::get<2>(tupleCoord);
        pub.publish(msg);
        tupleQueue.push(tupleCoord);

        rate.sleep();
    }
}
