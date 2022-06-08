#include <ros/ros.h>
#include <std_msgs/String.h>

#include <map>
#include <string>
#include <algorithm>

using namespace std;


map<std::string, int> wordDictionary;

void readerCallback(const std_msgs::String::ConstPtr &msg)
{
    string msg_data = msg->data;
    string chars(",.;");
    for (char c : chars) {
        msg_data.erase(remove(msg_data.begin(), msg_data.end(), c), msg_data.end());
    }

    vector<string> tokens;
    stringstream check(msg_data);
    string intermediate;

    while (getline(check, intermediate, ' ')) {
        tokens.push_back(intermediate);
    }

    for (int i = 0; i < tokens.size(); i++) {
        map<std::string, int>::iterator iter = wordDictionary.find(tokens[i]);
        if (iter != wordDictionary.end()) {
            iter->second++;
        } else {
            wordDictionary.insert(pair<string, int>(tokens[i], 1));
        }
    }
    
    map<std::string, int>::iterator iter;
    for (iter = wordDictionary.begin(); iter != wordDictionary.end(); iter++) {
        ROS_INFO_STREAM(iter->first << ": " << iter->second);
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "indexer");
    ros::NodeHandle nodeHandle;
    ros::Subscriber indexerSubscriber = nodeHandle.subscribe("reader", 100, readerCallback);
    ros::spin();

    return 0;
}