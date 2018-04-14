file(GLOB EngineFiles 
  engine/*.h
  engine/*.cc
)

source_group("engine" FILES ${EngineFiles})

add_library(blowbox-engine STATIC ${EngineFiles})

target_link_libraries(blowbox-engine PRIVATE
  blowbox-core 
  blowbox-graphics 
  blowbox-scripting 
  blowbox-builder
)

target_include_directories(blowbox-engine PRIVATE 
  "${CMAKE_SOURCE_DIR}/src/core" 
  "${CMAKE_SOURCE_DIR}/src/graphics" 
  "${CMAKE_SOURCE_DIR}/src/scripting" 
  "${CMAKE_SOURCE_DIR}/src/builder"
)