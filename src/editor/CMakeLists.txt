file(GLOB EditorFiles 
  editor/*.h
  editor/*.cc
)

source_group("editor" FILES ${EditorFiles})

set(CMAKE_AUTOMOC ON)
add_executable(blowbox-editor ${EditorFiles})

target_link_libraries(blowbox-editor PRIVATE
  blowbox-core 
  blowbox-engine
  Qt5::Widgets
)

target_include_directories(blowbox-editor PRIVATE 
  "${CMAKE_SOURCE_DIR}/src/engine" 
  "${CMAKE_SOURCE_DIR}/src/editor"
)
set(CMAKE_AUTOMOC OFF)