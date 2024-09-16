cmake_minimum_required(VERSION 3.15)
project(rfm_weather_api CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_library(rfm_weather_api src/tomorrow_io_weather_api.cpp)
target_include_directories(rfm_weather_api PUBLIC include)

# Need the package to request the weather data
find_package(rfm_http_requester REQUIRED)
# Need this package parse the json strings from the http requests
find_package(simdjson REQUIRED)


target_link_libraries(rfm_weather_api simdjson::simdjson)
target_link_libraries(rfm_weather_api rfm_http_requester::rfm_http_requester)

set(WEATHER_API_LIST_OF_HEADERS
  include/tomorrow_io_weather_api.hpp
  include/rfm_weather_api.h
)

add_executable(test main.cpp)
target_link_libraries(test rfm_weather_api)
set_target_properties(rfm_weather_api PROPERTIES PUBLIC_HEADER "${WEATHER_API_LIST_OF_HEADERS}")
install(TARGETS rfm_weather_api)
