#ifndef ros_handle_H
#define ros_handle_H
#include <ros/ros.h>
#include <string>
#include <iostream>

#include <std_msgs/Bool.h>
#include <std_msgs/Int32.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

using namespace std;

class ros_handle
{
private:
    // farme ID
    int FID = 0;

    //Topic name
    string depthTopic;
    string rgbTopic;
    string statusTopic;
    string localizeTopic;
    void initTopic();

    //callback
    void depthCallback(const sensor_msgs::ImageConstPtr& msg);
    void rgbCallback(const sensor_msgs::ImageConstPtr& msg);

    //convert


    //msgs for publishing


    // Publishers
    ros::Publisher pub_status;
    ros::Publisher pub_localize;

    // Subscribers
    image_transport::Subscriber sub_depth;
    image_transport::Subscriber sub_rgb;

public:
    ros_handle(/* args */);
    // init
    void init_ros();

    //data msg return
    cv::Mat depth_image;
    cv::Mat rgb_image;

    // data to publish
    int localize;   

    // publish done msgs
    void pub_done();

    // show image
    void showImg();
    
};

ros_handle::ros_handle()
{
    initTopic();
    init_ros();
    depth_image = cv::Mat::zeros(240, 320, CV_16UC1);
    rgb_image = cv::Mat::zeros(240, 320, CV_8UC3);
}
#endif