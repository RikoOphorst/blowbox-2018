file(GLOB EngineFiles 
  engine/*.h
  engine/*.cc
)

file(GLOB EngineServicesFiles 
  engine/services/*.h
  engine/services/*.cc
)

source_group("engine" FILES ${EngineFiles})
source_group("engine\\services" FILES ${EngineServicesFiles})

add_library(blowbox-engine STATIC 
  ${EngineFiles}
  ${EngineServicesFiles}
)

target_link_libraries(blowbox-engine PRIVATE
  blowbox-core 
  blowbox-graphics 
  blowbox-scripting 
  blowbox-builder
  itclap
)

target_include_directories(blowbox-engine PRIVATE 
  "${CMAKE_SOURCE_DIR}/src/core" 
  "${CMAKE_SOURCE_DIR}/src/graphics" 
  "${CMAKE_SOURCE_DIR}/src/scripting" 
  "${CMAKE_SOURCE_DIR}/src/builder"
)