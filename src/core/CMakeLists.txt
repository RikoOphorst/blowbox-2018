file(GLOB CoreFiles 
  core/*.h
  core/*.cc
)

file(GLOB CoreServicesFiles 
  core/services/*.h
  core/services/*.cc
)

file(GLOB CoreDataFiles 
  core/data/*.h
  core/data/*.cc
)

file(GLOB CoreUtilFiles 
  core/util/*.h
  core/util/*.cc
)

file(GLOB CoreMemoryFiles 
  core/memory/*.h
  core/memory/*.cc
)

file(GLOB CoreMemoryAllocatorsFiles 
  core/memory/allocators/*.h
  core/memory/allocators/*.cc
)

source_group("core" FILES ${CoreFiles})
source_group("core\\services" FILES ${CoreServicesFiles})
source_group("core\\data" FILES ${CoreDataFiles})
source_group("core\\util" FILES ${CoreUtilFiles})
source_group("core\\memory" FILES ${CoreMemoryFiles})
source_group("core\\memory\\allocators" FILES ${CoreMemoryAllocatorsFiles})

add_library(blowbox-core STATIC
  ${CoreFiles}
  ${CoreServicesFiles}
  ${CoreDataFiles}
  ${CoreUtilFiles}
  ${CoreMemoryFiles}
  ${CoreMemoryAllocatorsFiles}
)

target_link_libraries(blowbox-core PUBLIC 
  ieastl 
  iglm
  ifilesystem
)