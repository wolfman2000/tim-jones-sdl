cmake_minimum_required(VERSION 3.2)
project(TimJones)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${TimJones_SOURCE_DIR}/CMake/Modules")

set(TJ_BIN_DIR ${TimJones_SOURCE_DIR}/bin)

# Don't allow in-source builds.
# http://stackoverflow.q/1208681/445373
if ("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif()

# Set SDL2 up.
find_package(SDL2 REQUIRED)
find_package(SDL2Image REQUIRED)

add_subdirectory(src)

