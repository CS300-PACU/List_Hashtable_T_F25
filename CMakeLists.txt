# CMakeLists.txt at the root of the project

cmake_minimum_required(VERSION 3.0)

# Name SampleClass needs to match one of the Source names in Sources.
set(This TestSuite)

project(${This} C CXX)
set(CMAKE_C_STANDARD 99)
# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html#prop_tgt:CXX_STANDARD
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)


add_subdirectory(List)
#add_subdirectory(Hashtable)
