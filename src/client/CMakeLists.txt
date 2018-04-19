file(GLOB ClientFiles 
  client/*.h
  client/*.cc
)

if (WIN32)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif()

source_group("client" FILES ${ClientFiles})

add_executable(blowbox-client ${ClientFiles})

target_link_libraries(blowbox-client PRIVATE
  blowbox-core 
  blowbox-engine
)

target_include_directories(blowbox-client PRIVATE 
  "${CMAKE_SOURCE_DIR}/src/engine" 
  "${CMAKE_SOURCE_DIR}/src/core"
)