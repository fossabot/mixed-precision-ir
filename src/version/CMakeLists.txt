cmake_minimum_required(VERSION 3.22)
project(version C CXX)

set(SOURCE_FILES
	version.hpp
	version.cpp
)

add_library(version STATIC ${SOURCE_FILES})

install(TARGETS version DESTINATION ${IR_INSTALL_LIB_DIR})
install(FILES version.hpp DESTINATION ${IR_INSTALL_INCLUDE_DIR})
