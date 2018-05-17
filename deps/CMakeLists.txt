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
set (BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set (ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "" FORCE)
set (ASSIMP_INSTALL_PDB OFF CACHE BOOL "" FORCE)
set (ASSIMP_NO_EXPORT ON CACHE BOOL "" FORCE)
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
  IrrXML
  UpdateAssimpLibsDebugSymbolsAndDLLs
  zlib
  zlibstatic
)

# LuaJIT
set(LUAJIT_LIBRARY_NAMES
  lua51
  luajit
  minilua
)

foreach(CURRENT_LIB_NAME ${LUAJIT_LIBRARY_NAMES})
  if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/luajit/src/${CURRENT_LIB_NAME}.lib")
    set(LUAJIT_LIBRARIES ${LUAJIT_LIBRARIES} "${CMAKE_CURRENT_SOURCE_DIR}/luajit/src/${CURRENT_LIB_NAME}.lib")
  else()
    message (FATAL_ERROR "Could not find ${CURRENT_LIB_NAME}.lib in order to add LuaJIT. Did you build luajit? Run deps/luajit/src/msvcbuild.bat in a x64 Visual Studio Command Prompt and try running cmake again.")
  endif ()
endforeach ()

add_library(iluajit INTERFACE)
target_link_libraries(iluajit INTERFACE "${LUAJIT_LIBRARIES}")
target_include_directories(iluajit INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/luajit/src")

# DirectX 11
find_package(DirectX REQUIRED)
add_library(idirectx11 INTERFACE)
target_link_libraries(idirectx11 INTERFACE ${DirectX11_LIBRARIES})
target_include_directories(idirectx11 INTERFACE ${DirectX11_INCLUDE_DIRS})

# Filesystem
add_library(ifilesystem INTERFACE)
target_include_directories(ifilesystem INTERFACE "filesystem")

# TCLAP
add_library(itclap INTERFACE)
target_include_directories(itclap INTERFACE "tclap/include")