cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(rfm_weather_api CONFIG REQUIRED)

add_executable(example src/example.cpp)
target_link_libraries(example rfm_weather_api::rfm_weather_api)
