cmake_minimum_required(VERSION 3.16)

set(RAYLIB_PROJECT raylib_boilerplate)
set(RAYLIB_EXAMPLE raylib_example)

if(NOT DEFINED CMAKE_BUILD_PARALLEL_LEVEL)
  set(CMAKE_BUILD_PARALLEL_LEVEL 4)
endif()

set(CMAKE_C_STANDARD 11)

project(
  ${RAYLIB_PROJECT}
  VERSION 0.1.1
  DESCRIPTION "Raylib project boilerplate"
  LANGUAGES C)

find_package(raylib QUIET)

if(NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master)
  set(OpenGL_GL_PREFERENCE GLVND)
  FetchContent_MakeAvailable(raylib)
endif()

add_executable(${RAYLIB_EXAMPLE})

target_link_libraries(${RAYLIB_EXAMPLE} PRIVATE raylib)

if(APPLE)
  target_link_libraries(${RAYLIB_EXAMPLE} "-framework IOKit")
  target_link_libraries(${RAYLIB_EXAMPLE} "-framework Cocoa")
  target_link_libraries(${RAYLIB_EXAMPLE} "-framework OpenGL")
endif()

add_subdirectory(source)

enable_testing()


add_test(
  NAME ${RAYLIB_EXAMPLE}_test
  COMMAND ${RAYLIB_EXAMPLE} --test)