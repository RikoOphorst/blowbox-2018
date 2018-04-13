file(GLOB GraphicsFiles 
  graphics/*.h
  graphics/*.cc
)

source_group("graphics" FILES ${GraphicsFiles})

add_library(blowbox-graphics STATIC ${GraphicsFiles})

target_link_libraries(blowbox-graphics PRIVATE 
  blowbox-core 
  idirectx11
)

target_include_directories(blowbox-graphics PRIVATE 
  "${CMAKE_SOURCE_DIR}/src/core"
)