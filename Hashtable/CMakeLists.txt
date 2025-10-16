# CMakeLists.txt at the root of the project

cmake_minimum_required(VERSION 3.0)

# Name SampleClass needs to match one of the Source names in Sources.
set(This TestSuite_HT)

project(${This} C CXX)
set(CMAKE_C_STANDARD 99)
# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html#prop_tgt:CXX_STANDARD
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)


enable_testing()
if (NOT TARGET gtest)
	add_subdirectory(googletest)
endif()


 set (Headers
     include/ht.h
		 ../List/include/list.h
 )
 set (Sources
     src/ht.c
		 ../List/src/list.c
 )

add_library(${This} STATIC ${Sources} ${Headers})
add_subdirectory(test)

