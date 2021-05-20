# Josh Schmitz
# CMakeLists.txt
# April 2021
# builds executables for project_tests.cpp and project_perf.cpp

project(KnightsTour)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O0")
set(CMAKE_BUILD_TYPE Debug)

# locate gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# create unit test executable
add_executable(project_tests
               knights_tour.cpp
               project_tests.cpp)
target_link_libraries(project_tests ${GTEST_LIBRARIES} pthread)

# create performance test executable
add_executable(project_perf
               knights_tour.cpp
               project_perf.cpp)