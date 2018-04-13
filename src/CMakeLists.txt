add_subdirectory("core")

add_subdirectory("graphics")
add_subdirectory("scripting")
add_subdirectory("builder")
add_subdirectory("engine")

add_subdirectory("client")

if (BLOWBOX_BUILD_EDITOR EQUAL ON)
  add_subdirectory("editor")
endif (BLOWBOX_BUILD_EDITOR EQUAL ON)