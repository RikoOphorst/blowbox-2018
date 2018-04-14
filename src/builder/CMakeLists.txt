file(GLOB BuilderFiles 
  builder/*.h
  builder/*.cc
)

source_group("builder" FILES ${BuilderFiles})

add_library(blowbox-builder STATIC ${BuilderFiles})

target_link_libraries(blowbox-builder PRIVATE
  blowbox-core
  idirectx11
  assimp
)

target_include_directories(blowbox-builder PRIVATE 
  "${CMAKE_SOURCE_DIR}/src/core"
)