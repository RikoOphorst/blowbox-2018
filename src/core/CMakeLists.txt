file(GLOB CoreFiles 
  core/*.h
  core/*.cc
)

source_group("core" FILES ${CoreFiles})

add_library(blowbox-core STATIC ${CoreFiles})

target_link_libraries(blowbox-core PUBLIC 
  ieastl 
  iglm
  ifilesystem
)