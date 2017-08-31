cmake_minimum_required(VERSION 2.8)
project(acoap)
set(acoap_VERSION_MAJOR 0)
set(acoap_VERSION_MINOR 1)

configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(libacoap
  src/coap.cpp
  src/coap_header.cpp
)

add_executable(server examples/apps/echo/server.cpp)
target_link_libraries(server libacoap)
