cmake_minimum_required(VERSION 3.22)
set(lib_name versionLib)
project(${lib_name} CXX)

set(SOURCE_FILES
	version.hpp
	version.cpp
)

add_library(${lib_name} STATIC ${SOURCE_FILES})
set(folder "Libraries")
set_target_properties(${lib_name} PROPERTIES FOLDER ${folder})

install(TARGETS ${lib_name} DESTINATION ${MPIR_INSTALL_LIB_DIR})
install(FILES version.hpp DESTINATION ${MPIR_INSTALL_INCLUDE_DIR})
