cmake_minimum_required(VERSION 3.10)

project(SFU
  VERSION 1.0
  DESCRIPTION "A Selective Forwarding Unit media server"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(app)
add_subdirectory(server)
add_subdirectory(cli)