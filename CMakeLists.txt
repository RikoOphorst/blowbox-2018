cmake_minimum_required (VERSION 3.11)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(blowbox)

# Enable folders inside of the solution
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Set the cmake targets to be stored in the deps/cmake folder inside of the solution
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "deps/cmake")

# Define _CRT_SECURE_NO_WARNINGS for all C++ files disabling warnings thrown by compilers when using functions like scanf()
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
  message (FATAL_ERROR "Blowbox must be built as a 64 bit project so you should use a 64 bit compiler when configuring through CMake.")
endif(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)

# This function set_solution_folder is courtesy of Daniel Konings http://www.danielkonings.com/
function (set_solution_folder arg1)
  if (MSVC)
    set(SolutionFolder "${arg1}")
    foreach (Target ${ARGV})
      if (NOT "${Target}" STREQUAL "${SolutionFolder}")
        set_target_properties("${Target}" PROPERTIES FOLDER "${SolutionFolder}")
      endif ()
    endforeach ()
  endif (MSVC)
endfunction (set_solution_folder)

add_subdirectory("deps")
add_subdirectory("src")