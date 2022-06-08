cmake_minimum_required(VERSION 3.0.2)
project(temp_converter_ros_pkg)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros, libraries and other packages
find_package(catkin REQUIRED COMPONENTS
	roscpp
  std_msgs
  message_generation
)

## Generate messages in the 'msg' folder
add_message_files(
	FILES
	CelsiusTemperature.msg
	FahrenheitTemperature.msg
	KelvinTemperature.msg
)

## Generate services in the 'srv' folder
add_service_files(
	FILES
	Celsius2Fahrenheit.srv
	Celsius2Kelvin.srv
	Fahrenheit2Celsius.srv
	Fahrenheit2Kelvin.srv
	Kelvin2Celsius.srv
	Kelvin2Fahrenheit.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
	DEPENDENCIES
	std_msgs
)

## Declare a catkin package
catkin_package(
	CATKIN_DEPENDS message_runtime std_msgs
)

## Specify additional locations of header files
include_directories(
	include
  ${catkin_INCLUDE_DIRS}
)

## Celsius2Fahrenheit
add_executable(Celsius2FahrenheitServer src/Celsius2FahrenheitServer.cpp)
target_link_libraries(Celsius2FahrenheitServer ${catkin_LIBRARIES})
add_dependencies(Celsius2FahrenheitServer temp_converter_ros_pkg_gencpp)

add_executable(Celsius2FahrenheitClient src/Celsius2FahrenheitClient.cpp)
target_link_libraries(Celsius2FahrenheitClient ${catkin_LIBRARIES})
add_dependencies(Celsius2FahrenheitClient temp_converter_ros_pkg_gencpp)

## Celsius2Kelvin
add_executable(Celsius2KelvinServer src/Celsius2KelvinServer.cpp)
target_link_libraries(Celsius2KelvinServer ${catkin_LIBRARIES})
add_dependencies(Celsius2KelvinServer temp_converter_ros_pkg_gencpp)

add_executable(Celsius2KelvinClient src/Celsius2KelvinClient.cpp)
target_link_libraries(Celsius2KelvinClient ${catkin_LIBRARIES})
add_dependencies(Celsius2KelvinClient temp_converter_ros_pkg_gencpp)

## Fahrenheit2Celsius
add_executable(Fahrenheit2CelsiusServer src/Fahrenheit2CelsiusServer.cpp)
target_link_libraries(Fahrenheit2CelsiusServer ${catkin_LIBRARIES})
add_dependencies(Fahrenheit2CelsiusServer temp_converter_ros_pkg_gencpp)

add_executable(Fahrenheit2CelsiusClient src/Fahrenheit2CelsiusClient.cpp)
target_link_libraries(Fahrenheit2CelsiusClient ${catkin_LIBRARIES})
add_dependencies(Fahrenheit2CelsiusClient temp_converter_ros_pkg_gencpp)

## Fahrenheit2Kelvin
add_executable(Fahrenheit2KelvinServer src/Fahrenheit2KelvinServer.cpp)
target_link_libraries(Fahrenheit2KelvinServer ${catkin_LIBRARIES})
add_dependencies(Fahrenheit2KelvinServer temp_converter_ros_pkg_gencpp)

add_executable(Fahrenheit2KelvinClient src/Fahrenheit2KelvinClient.cpp)
target_link_libraries(Fahrenheit2KelvinClient ${catkin_LIBRARIES})
add_dependencies(Fahrenheit2KelvinClient temp_converter_ros_pkg_gencpp)

## Kelvin2Celsius
add_executable(Kelvin2CelsiusServer src/Kelvin2CelsiusServer.cpp)
target_link_libraries(Kelvin2CelsiusServer ${catkin_LIBRARIES})
add_dependencies(Kelvin2CelsiusServer temp_converter_ros_pkg_gencpp)

add_executable(Kelvin2CelsiusClient src/Kelvin2CelsiusClient.cpp)
target_link_libraries(Kelvin2CelsiusClient ${catkin_LIBRARIES})
add_dependencies(Kelvin2CelsiusClient temp_converter_ros_pkg_gencpp)

## Kelvin2Fahrenheit
add_executable(Kelvin2FahrenheitServer src/Kelvin2FahrenheitServer.cpp)
target_link_libraries(Kelvin2FahrenheitServer ${catkin_LIBRARIES})
add_dependencies(Kelvin2FahrenheitServer temp_converter_ros_pkg_gencpp)

add_executable(Kelvin2FahrenheitClient src/Kelvin2FahrenheitClient.cpp)
target_link_libraries(Kelvin2FahrenheitClient ${catkin_LIBRARIES})
add_dependencies(Kelvin2FahrenheitClient temp_converter_ros_pkg_gencpp)