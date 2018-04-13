file(GLOB BuilderFiles 
  builder/*.h
  builder/*.cc
)

source_group("builder" FILES ${BuilderFiles})

add_library(blowbox-builder STATIC ${BuilderFiles})

target_link_libraries(blowbox-builder   blowbox-core)

target_include_directories(blowbox-builder PRIVATE "${CMAKE_SOURCE_DIR}/src/core")