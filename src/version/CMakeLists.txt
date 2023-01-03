cmake_minimum_required(VERSION 3.22)
project(version C CXX)

set(SOURCE_FILES
	version.hpp
	version.cpp
)

add_library(version STATIC ${SOURCE_FILES})

install(TARGETS version DESTINATION ${MPIR_INSTALL_LIB_DIR})
install(FILES version.hpp DESTINATION ${MPIR_INSTALL_INCLUDE_DIR})
