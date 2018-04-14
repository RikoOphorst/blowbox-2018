cmake_minimum_required (VERSION 3.11)
cmake_policy(SET CMP0017 NEW)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_AUTOMOC ON)

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

# Add the CMAKE_PREFIX_PATH to the cache so it's easier to set from the CMake GUI
set(CMAKE_PREFIX_PATH "" CACHE PATH "CMAKE_PREFIX_PATH")

# Enable treat warnings as error
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX")

include("cmake/SetSolutionFolder.cmake")
add_subdirectory("deps")
add_subdirectory("src")
