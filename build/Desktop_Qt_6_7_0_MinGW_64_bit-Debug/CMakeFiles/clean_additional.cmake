# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Assignment1_autogen"
  "CMakeFiles\\Assignment1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Assignment1_autogen.dir\\ParseCache.txt"
  )
endif()
