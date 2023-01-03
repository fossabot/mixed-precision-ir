cmake_minimum_required(VERSION 3.22)
project(ir)

add_subdirectory(version)
set(SOURCE_FILES main.cpp)

add_executable(version ${SOURCE_FILES})
target_link_libraries(version version)
install(TARGETS version DESTINATION ${IR_INSTALL_BIN_DIR})
