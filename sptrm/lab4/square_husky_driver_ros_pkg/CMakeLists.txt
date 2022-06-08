cmake_minimum_required(VERSION 3.0.2)
project(square_husky_driver_ros_pkg)

## Compile as C++11
add_compile_options(-std=c++11)

## Find catkin macros, libraries and other packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

# Declare a package
catkin_package()

# Specify additional locations of header files
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# Add executable and link libraries
add_executable(huskyDriverPublisher src/huskyDriverPublisher.cpp)
target_link_libraries(huskyDriverPublisher ${catkin_LIBRARIES})
