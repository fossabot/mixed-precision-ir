cmake_minimum_required(VERSION 3.22)
project(multifile CXX)

add_subdirectory(${MPIR_ROOT_DIR}/ext/stillwater-sc/universal build_universal) 
include_directories(${MPIR_ROOT_DIR}/ext/stillwater-sc/universal/include)

# source files that make up the command
set(SOURCE_FILES
	integers.cpp
	fixpnts.cpp
	areals.cpp
	cfloats.cpp
	posits.cpp
	logs.cpp
	unums.cpp
	main.cpp
)

add_executable(multifile ${SOURCE_FILES})
# add libraries if you need them
#target_link_libraries(multifile required-library1 required-library2)
install(TARGETS multifile DESTINATION ${MPIR_INSTALL_BIN_DIR})
#install(FILES my-consolidated-include.hpp DESTINATION ${MPIR_INSTALL_INCLUDE_DIR})
