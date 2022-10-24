cmake_minimum_required(VERSION 3.20)


project(executor LANGUAGES CXX)


#set(CMAKE_INCLUDE_CURRENT_DIR)
include_directories(./include/)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
#set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -Og")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

## default cfg (can be changed during build through cmdline arg)
set(CMAKE_BUILD_TYPE RelWithDebInfo)


add_executable(executor
  ./src/main.cpp
  ./src/except.cpp
  ./src/register.cpp
  ./src/register_file.cpp
  ./src/memory.cpp
  ./src/cpu.cpp
  ./src/soc.cpp
  )
