project (server)

add_library(${PROJECT_NAME} src/server.cpp)

target_include_directories( ${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)