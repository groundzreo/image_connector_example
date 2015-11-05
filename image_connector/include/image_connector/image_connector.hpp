/*
  Image Connector.hpp

  Subscribes image topic, processes it, and publishes string message
*/


#ifndef _IMAGE_CONNECTOR_IMAGE_CONNECTOR_HPP_
#define _IMAGE_CONNECTOR_IMAGE_CONNECTOR_HPP_

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/Image.h>
#include <std_msgs/String.h>

class ImageConnector {
  public:
    // constructor and destructor
    ImageConnector();
    ImageConnector(const std::string& sub_img_topic, const std::string& pub_str_topic);
    ~ImageConnector();

    void spin();
  protected:
    void init(const std::string& sub_img_topic, const std::string& pub_str_topic);

    // Image callback. 
    void imageCB(const sensor_msgs::ImageConstPtr& msg);

    std::string processImage(const sensor_msgs::ImageConstPtr& image);
  private:
    ros::NodeHandle nh_;

    std::string sub_image_topic_;
    std::string pub_str_topic_; 

    // For image processing in ROS
    image_transport::ImageTransport it_;
    image_transport::Subscriber sub_image_;

    // to publish string message
    ros::Publisher pub_str_;
};

#endif // _IMAGE_CONNECTOR_IMAGE_CONNECTOR_HPP_
