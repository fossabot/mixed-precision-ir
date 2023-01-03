cmake_minimum_required(VERSION 3.22)
project(ir C CXX)

set(SOURCE_FILES
	version.hpp
	version.cpp
)

add_library(ir STATIC ${SOURCE_FILES})

install(TARGETS ir DESTINATION ${IR_INSTALL_LIB_DIR})
install(FILES version.hpp DESTINATION ${IR_INSTALL_INCLUDE_DIR})
