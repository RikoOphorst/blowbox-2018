cmake_minimum_required (VERSION 3.11)
cmake_policy(SET CMP0017 NEW)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

project(blowbox)

# Enable folders inside of the solution
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Set the cmake targets to be stored in the deps/cmake folder inside of the solution
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "deps/cmake")

# Define _CRT_SECURE_NO_WARNINGS for all C++ files disabling warnings thrown by compilers when using functions like scanf()
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

# Crash if building for non 64-bit targets
if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
  message (FATAL_ERROR "Blowbox must be built as a 64 bit project so you should use a 64 bit compiler when configuring through CMake.")
endif(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)

include("cmake/SetSolutionFolder.cmake")

# Add the dependencies to the project.
add_subdirectory("deps")

# QT5 DEPENDENCY / PROJECT FINDING
# This HAS TO happen in this CMakeLists.txt at the root of the project
# Otherwise the other build targets for whatever reason can not find
# the Qt5::Widgets target. This took me about 8 hours to figure out.
# Also, we add the CMAKE_PREFIX_PATH to the cache so it's easier to 
# set from the CMake GUI.
set(CMAKE_PREFIX_PATH "" CACHE PATH "CMAKE_PREFIX_PATH")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if (NOT Qt5_FOUND)
  message(FATAL_ERROR "Could not find Qt. Make sure to set the CMAKE_PREFIX_PATH to wherever your Qt 5.10.1 msvc2017_64 installation is located.")
endif ()

#foreach(plugin ${Qt5Widgets_PLUGINS})
#  get_target_property(_loc ${plugin} LOCATION)
#  message("Plugin ${plugin} is at location ${_loc}")
#endforeach()

# Enable treat warnings as error, only for blowbox projects
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX")

add_subdirectory("src")
