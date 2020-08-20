cmake_minimum_required(VERSION 3.1)

project(FacialDetection VERSION 1.0.0)

find_package(OpenCV REQUIRED)

message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")



add_executable(FacialDetection FacialDetection.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(FacialDetection PUBLIC ${OpenCV_LIBS})

