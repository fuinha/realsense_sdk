cmake_minimum_required(VERSION 2.8)
project(rs_playback_sample)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(${PROJECT_NAME} playback_sample.cpp)

target_link_libraries(${PROJECT_NAME} realsense
                                      rs_image rs_playback rs_log_utils
                                      pthread
                                      opencv_imgproc opencv_core)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

