# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GoToCell_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GoToCell_autogen.dir\\ParseCache.txt"
  "GoToCell_autogen"
  )
endif()
