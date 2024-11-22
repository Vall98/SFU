cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

message(CMAKE_TOOLCHAIN_FILE="${CMAKE_TOOLCHAIN_FILE}")

include_directories(${CMAKE_SOURCE_DIR})
include_directories($ENV{VCPKG_ROOT}/installed/x64-windows/include)

add_library(${PROJECT_NAME} src/server.cpp)

target_include_directories( ${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)