cmake_minimum_required(VERSION 3.23)
project(VehicleRentalApplications)

set(CMAKE_CXX_STANDARD 14)

add_executable(VehicleRentalApplications "Source Files/main.cpp" "Source Files/Vehicle.cpp" "Header Files/Vehicle.h" "Header Files/Car.h" "Source Files/Car.cpp" "Source Files/Bike.cpp" "Header Files/Bike.h")
