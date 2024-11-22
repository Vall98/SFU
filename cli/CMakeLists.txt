cmake_minimum_required(VERSION 3.10)
project (cli)

add_library(${PROJECT_NAME} src/cli.cpp)

target_include_directories(cli PRIVATE ../server/include)

target_include_directories( ${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)