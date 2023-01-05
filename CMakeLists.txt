cmake_minimum_required(VERSION 3.22)

project(mixed-precision-ir)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "C++20 has been enabled by default")

# Compiler specific environments
if(CMAKE_COMPILER_IS_GNUCXX OR MINGW OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

	# include code quality flags
	set(EXTRA_C_FLAGS "${EXTRA_C_FLAGS} -Wall -Wpedantic -Wno-narrowing -Wno-deprecated")
	# specific flags for debug and release builds
	#set(EXTRA_C_FLAGS_RELEASE "${EXTRA_C_FLAGS_RELEASE} -O3 -DNDEBUG")
	#set(EXTRA_C_FLAGS_DEBUG "${EXTRA_C_FLAGS_DEBUG} -g3 -pthread")

elseif(MSVC)
	# include code quality flags
	set(EXTRA_C_FLAGS "${EXTRA_C_FLAGS} /MP")
#	add_definitions(-D _CRT_SECURE_NO_WARNINGS)
#	add_definitions(-D _SCL_SECURE_NO_WARNINGS)

    set(EXTRA_C_FLAGS "${EXTRA_C_FLAGS} /Zc:__cplusplus")

endif()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(MPIR_ROOT_DIR ${PROJECT_SOURCE_DIR})
set(MPIR_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(MPIR_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(MPIR_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

# constituent library headers
set(IR_INCLUDE_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/ir)
set(VERSION_INCLUDE_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/version)

add_definitions(-D UNIVERSAL_ENABLE_TEST=OFF)

include_directories(${MPIR_INSTALL_INCLUDE_DIR})
include_directories(${IR_INCLUDE_HEADERS_DIR})
include_directories(${VERSION_INCLUDE_HEADERS_DIR})

# Universal is a C++ header-only library, so we do not need to build anything
# if you do add this line, you will get all the Universal regression tests,
# playground, education, applications, and command line utilities.
# You can only add this build subdirectory to ONE and only ONE project
# within the IR workspace. Multiple includes will yield multiple definitions
# of build, install, and uninstall targets.
add_subdirectory(${MPIR_ROOT_DIR}/ext/stillwater-sc/universal build_universal) 

add_subdirectory(src)
add_subdirectory(test)
