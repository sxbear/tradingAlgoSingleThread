# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Project's name
project(TASTSXB)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Add all .cpp files in src/ to the SOURCE variable
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Tell CMake to build an executable using all the source files
add_executable(${PROJECT_NAME} ${SOURCES})

find_package(CURL REQUIRED)
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES})
endif()
