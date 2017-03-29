cmake_minimum_required(VERSION 2.8)
project(WXCALC)

if (DEFINED DEVEL)
  add_definitions(-DDEBUG=${DEBUG})
  set(CMAKE_BUILD_TYPE Debug)
  message("Building a debug release")
else()
  set(CMAKE_BUILD_TYPE Release)
  message("Building an optimized release")
endif()

# allow me build with useful warnings
if (DEFINED DEVEL AND NOT DEVEL EQUAL 0)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror") 
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") 
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra") 
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weffc++") 
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic") 
endif()

# use c++ 11 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") 

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(wxWidgets COMPONENTS core base REQUIRED)

add_subdirectory("src")
