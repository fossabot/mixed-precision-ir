cmake_minimum_required(VERSION 3.22)
project(ir)

add_subdirectory(ir)
set(SOURCE_FILES main.cpp)

add_executable(ir ${SOURCE_FILES})
target_link_libraries(ir ir)
install(TARGETS ir DESTINATION ${IR_INSTALL_BIN_DIR})
