set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

if (WIN32)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif()

file(GLOB EditorFiles 
  editor/*.h
  editor/*.cc
  editor/*.ui
)

file(GLOB EditorWindowsFiles
  editor/windows/*.h
  editor/windows/*.cc
  editor/windows/*.ui
)

file(GLOB QRCFiles
  style/*.qrc
  style/*.qss
)

source_group("editor" FILES ${EditorFiles})
source_group("editor\\windows" FILES ${EditorWindowsFiles})
source_group("style" FILES ${QRCFiles})

add_executable(blowbox-editor 
  ${EditorFiles}
  ${EditorWindowsFiles}
  ${QRCFiles}
)

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
set(CMAKE_AUTORCC OFF)