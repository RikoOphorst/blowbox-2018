# EASTL
set(EASTL_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory("eastl")
add_subdirectory("eastl/test/packages/EAAssert")
add_subdirectory("eastl/test/packages/EAStdC")
add_subdirectory("eastl/test/packages/EAMain")
add_subdirectory("eastl/test/packages/EATest")
add_subdirectory("eastl/test/packages/EAThread")

add_library(ieastl INTERFACE)
target_link_libraries(ieastl INTERFACE EASTL EAAssert EAStdC EAMain EATest EAThread)
target_include_directories(ieastl INTERFACE "eastl/include")

set_solution_folder(
  "deps/eastl"
  EABase_ide
  EASTL
  EAAssert_ide
  EAMain_ide
  EAStdC
  EATest
  EAThread_ide
)

# GLM
add_library(iglm INTERFACE)
target_include_directories(iglm INTERFACE "glm")

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)

add_subdirectory("glfw")

set_solution_folder(
  "deps/glfw"
  glfw
  uninstall
)

# Assimp
set (ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT OFF CACHE BOOL "" FORCE)
set (ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set (ASSIMP_BUILD_OBJ_IMPORTER ON CACHE BOOL "" FORCE)
set (ASSIMP_BUILD_FBX_IMPORTER ON CACHE BOOL "" FORCE)
set (ASSIMP_BUILD_OPENGEX_IMPORTER ON CACHE BOOL "" FORCE)
set (ASSIMP_INCLUDE_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assimp/include/" CACHE PATH "" FORCE)
add_subdirectory("assimp")

add_library(iassimp INTERFACE)
target_link_libraries(iassimp INTERFACE assimp)
target_include_directories(iassimp INTERFACE "assimp/include")

set_solution_folder(
  "deps/assimp"
  assimp
  assimp_cmd
  IrrXML
  UpdateAssimpLibsDebugSymbolsAndDLLs
  zlib
  zlibstatic
)

# DirectX 11
find_package(DirectX REQUIRED)
add_library(idirectx11 INTERFACE)
target_link_libraries(idirectx11 INTERFACE ${DirectX11_LIBRARIES})
target_include_directories(idirectx11 INTERFACE ${DirectX11_INCLUDE_DIRS})

# Qt
FIND_PACKAGE(Qt5 COMPONENTS Widgets REQUIRED)
IF (NOT Qt5_FOUND)
  MESSAGE(FATAL_ERROR "In order to build the tools projects, Qt5 needs to be installed on the system")
ENDIF ()

# Mono
find_package(Mono REQUIRED)