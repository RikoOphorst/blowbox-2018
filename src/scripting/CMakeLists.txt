file(GLOB ScriptingFiles 
  scripting/*.h
  scripting/*.cc
)

source_group("scripting" FILES ${ScriptingFiles})

add_library(blowbox-scripting STATIC ${ScriptingFiles})

target_link_libraries(blowbox-scripting PRIVATE
  blowbox-core
  iluajit
)

target_include_directories(blowbox-scripting PRIVATE 
  "${CMAKE_SOURCE_DIR}/src/core"
)