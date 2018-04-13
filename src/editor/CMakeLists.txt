file(GLOB EditorFiles 
  editor/*.h
  editor/*.cc
)

source_group("editor" FILES ${EditorFiles})

add_executable(blowbox-editor ${EditorFiles})

target_link_libraries(blowbox-editor blowbox-core)
target_link_libraries(blowbox-editor blowbox-engine)

target_include_directories(blowbox-editor PRIVATE "${CMAKE_SOURCE_DIR}/src/engine")
target_include_directories(blowbox-editor PRIVATE "${CMAKE_SOURCE_DIR}/src/editor")