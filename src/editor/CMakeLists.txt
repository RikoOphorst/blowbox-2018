set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB EditorFiles 
  editor/*.h
  editor/*.cc
)

file(GLOB EditorUiFiles
  editor/ui/*.ui
  editor/ui/*.h
  editor/ui/*.cc
)

source_group("editor" FILES ${EditorFiles})
source_group("editor\\windows" FILES ${EditorUiFiles})

add_executable(blowbox-editor 
  ${EditorFiles}
  ${EditorUiFiles}
)

set_property(TARGET blowbox-editor PROPERTY AUTOMOC_SOURCE_GROUP "editor\\autogen")

target_link_libraries(blowbox-editor PRIVATE
  blowbox-core 
  blowbox-engine
  blowbox-builder
  Qt5::Widgets
)

target_include_directories(blowbox-editor PRIVATE 
  "${CMAKE_SOURCE_DIR}/src/engine" 
  "${CMAKE_SOURCE_DIR}/src/editor"
  "${CMAKE_SOURCE_DIR}/src/builder"
)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC OFF)