cmake_minimum_required(VERSION 3.14...3.22)

## ---- Project ----

## Note: update this to your new project's name and version
project(
  xEqt0R
  VERSION 0.1
  LANGUAGES CXX
)

## ---- Include guards ----

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
    "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

## ---- Add dependencies via CPM ----
## see https://github.com/TheLartians/CPM.cmake for more info

#include(cmake/CPM.cmake)

## PackageProject.cmake will be used to make our target installable
#CPMAddPackage("gh:0xD503/xEqt0R.cmake@1.0.0")

#CPMAddPackage(
#  NAME libname
#  GIT_TAG 7.7.7
#  GITHUB_REPOSITORY libauthor/libname
#  OPTIONS "LIBNAME_INSTALL YES"       ## create an installable target
#)

## ---- Add source files ----

## Note: globbing sources is considered bad practice as CMake's generators may not detect new files
## automatically. Keep that in mind when changing files, or explicitly mention them here.
# file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
# file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")
#set(CMAKE_INCLUDE_CURRENT_DIR)


## ---- Create library ----

## Note: for header-only libraries change all PUBLIC flags to INTERFACE and create an interface
## target: add_library(${PROJECT_NAME} INTERFACE)
#add_library(${PROJECT_NAME} ${headers} ${sources})


#set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
## flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Weffc++")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
#set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -Og")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


## default cfg (can be changed during build through cmdline arg)
set(CMAKE_BUILD_TYPE RelWithDebInfo)


## being a cross-platform target, we enforce standards conformance on MSVC
#target_compile_options(${PROJECT_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")


## Link dependencies
#target_link_libraries(${PROJECT_NAME} PRIVATE libname::libname)

include_directories(./include/)
#target_include_directories(
#  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>
#                         $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
#)


## ---- Create an installable target ----
## this allows users to install and find the library via `find_package()`.

## the location where the project's version header will be placed should match the project's regular
## header paths
#string(TOLOWER ${PROJECT_NAME}/version.h VERSION_HEADER_LOCATION)

#packageProject(
#  NAME ${PROJECT_NAME}
#  VERSION ${PROJECT_VERSION}
#  NAMESPACE ${PROJECT_NAME}
#  BINARY_DIR ${PROJECT_BINARY_DIR}
#  INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include
#  INCLUDE_DESTINATION include/${PROJECT_NAME}-${PROJECT_VERSION}
#  VERSION_HEADER "${VERSION_HEADER_LOCATION}"
#  COMPATIBILITY SameMajorVersion
#  DEPENDENCIES "libname 7.7.7"
#)


add_executable(xEqt0R
  ./src/main.cpp
  #./src/except.cpp
  #./src/mapping_tables.cpp
  ./src/register.cpp
  ./src/register_file.cpp
  ./src/memory.cpp
  ./src/device.cpp
  ./src/cpu.cpp
  ./src/soc.cpp
)
