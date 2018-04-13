file(GLOB ClientFiles 
  client/*.h
  client/*.cc
)

source_group("client" FILES ${ClientFiles})

add_executable(blowbox-client ${ClientFiles})

target_link_libraries(blowbox-client 
  blowbox-core 
  blowbox-engine
)

target_include_directories(blowbox-client PRIVATE 
  "${CMAKE_SOURCE_DIR}/src/engine" 
  "${CMAKE_SOURCE_DIR}/src/core"
)