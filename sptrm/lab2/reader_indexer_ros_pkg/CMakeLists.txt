cmake_minimum_required(VERSION 3.0.2)
project(reader_indexer_ros_pkg)

## Define compile options
add_compile_options(-std=c++11)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs)

## Declare a catkin package
catkin_package()

## Build reader and indexer
include_directories(include ${catkin_INCLUDE_DIRS})

## Add reader
add_executable(reader src/reader.cpp)
target_link_libraries(reader ${catkin_LIBRARIES})

## Add indexer
add_executable(indexer src/indexer.cpp)
target_link_libraries(indexer ${catkin_LIBRARIES})
