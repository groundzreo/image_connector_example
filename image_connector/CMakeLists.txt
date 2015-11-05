cmake_minimum_required(VERSION 2.8.3)
project(image_connector)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  image_transport
  cv_bridge
  std_msgs
  sensor_msgs
)

find_package(OpenCV)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp image_transport cv_bridge std_msgs sensor_msgs
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(include)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(image_connector_node src/image_connector_node.cpp
                                    src/image_connector.cpp)
target_link_libraries(image_connector_node ${OpenCV_LIBRARIES} ${catkin_LIBRARIES})
