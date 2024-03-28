# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\HexSpinBox_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\HexSpinBox_autogen.dir\\ParseCache.txt"
  "HexSpinBox_autogen"
  )
endif()
