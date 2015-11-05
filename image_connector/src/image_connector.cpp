/*
  Image Connector.cpp

  Detailed member functions for image connector class
*/
#include "image_connector/image_connector.hpp"

/* 
  Constructor
  Instantiates all member variables
*/ 
ImageConnector::ImageConnector() : nh_(), it_(nh_)
{
  init("image", "string");
}

ImageConnector::ImageConnector(const std::string& sub_img_topic, const std::string& pub_str_topic) : nh_(), it_(nh_)
{
  init(sub_img_topic, pub_str_topic);  
}

// Destructor. Keep it for the future
ImageConnector::~ImageConnector() {
}

// Init. Instantiates Pub/subs
void ImageConnector::init(const std::string& sub_img_topic, const std::string& pub_str_topic)
{
  sub_image_topic_ = sub_img_topic;
  pub_str_topic_ = pub_str_topic;

  sub_image_ = it_.subscribe(sub_image_topic_, 1, &ImageConnector::imageCB, this);
  pub_str_ = nh_.advertise<std_msgs::String>(pub_str_topic_, 5);
}

void ImageConnector::spin() {
  ros::spin();
}

void ImageConnector::imageCB(const sensor_msgs::ImageConstPtr& msg) {
  ROS_INFO("Received Image");
}

std::string ImageConnector::processImage(const sensor_msgs::ImageConstPtr& image) {
  return "Hello";
}

