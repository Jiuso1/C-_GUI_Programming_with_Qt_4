# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QuitButton_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QuitButton_autogen.dir\\ParseCache.txt"
  "QuitButton_autogen"
  )
endif()
