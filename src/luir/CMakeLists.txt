cmake_minimum_required(VERSION 3.22)
project(luir CXX)

add_subdirectory(${MPIR_ROOT_DIR}/ext/stillwater-sc/universal build_universal) 
include_directories(${MPIR_ROOT_DIR}/ext/stillwater-sc/universal/include)

# source files that make up the command
set(SOURCE_FILES
	configs.hpp
	luir.cpp
)

add_executable(luir ${SOURCE_FILES})
# add libraries if you need them
#target_link_libraries(luir required-library1 required-library2)
install(TARGETS luir DESTINATION ${MPIR_INSTALL_BIN_DIR})
#install(FILES my-consolidated-include.hpp DESTINATION ${MPIR_INSTALL_INCLUDE_DIR})
