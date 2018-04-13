file(GLOB EngineFiles 
  engine/*.h
  engine/*.cc
)

source_group("engine" FILES ${EngineFiles})

add_library(blowbox-engine STATIC ${EngineFiles})

target_link_libraries(blowbox-engine    blowbox-core)
target_link_libraries(blowbox-engine    blowbox-graphics)
target_link_libraries(blowbox-engine    blowbox-scripting)
target_link_libraries(blowbox-engine    blowbox-builder)

target_include_directories(blowbox-engine PRIVATE "${CMAKE_SOURCE_DIR}/src/core")
target_include_directories(blowbox-engine PRIVATE "${CMAKE_SOURCE_DIR}/src/graphics")
target_include_directories(blowbox-engine PRIVATE "${CMAKE_SOURCE_DIR}/src/scripting")
target_include_directories(blowbox-engine PRIVATE "${CMAKE_SOURCE_DIR}/src/builder")