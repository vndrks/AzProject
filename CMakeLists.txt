cmake_minimum_required (VERSION 3.8)
#project (AZ_Project)
message( "Module - AZ_Project" )

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)


if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)

add_subdirectory ( AzChain )
add_subdirectory ( AzComponents )
add_subdirectory ( AzNetwork )
add_subdirectory ( AzUtil )
add_subdirectory ( MainApp )
add_subdirectory ( TestModule/Block )
add_subdirectory ( TestModule/AsyncInOut )
add_subdirectory ( TestModule/Crypto )