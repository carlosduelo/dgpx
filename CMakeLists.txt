cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(dgpx)

# Check and Activate C++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)

if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
  message( ERROR "C++ compiler does not support C++11" )
endif()

add_subdirectory(src)
