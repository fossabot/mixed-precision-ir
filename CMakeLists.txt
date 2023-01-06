cmake_minimum_required(VERSION 3.22)

if(NOT DEFINED MPIR_MAJOR)
	set(MPIR_MAJOR 0)
endif()
if(NOT DEFINED MPIR_MINOR)
	set(MPIR_MINOR 8)
endif()
if(NOT DEFINED MPIR_PATCH)
	set(MPIR_PATCH 1)
endif()
project(mixed-precision-ir
	DESCRIPTION "High-Performance Mixed-Precision Iterative Refinement algorithm development environment"
	VERSION "${MPIR_MAJOR}.${MPIR_MINOR}.${MPIR_PATCH}"
	LANGUAGES C CXX
	HOMEPAGE_URL "https://github.com/jamesquinlan/mixed-precision-ir")

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

find_package(Boost)
if(Boost_FOUND)
	message(STATUS "Boost_INCLUDE_DIR" ${Boost_INCLUDE_DIR})
	include_directories(${Boost_INCLUDE_DIR})
endif(Boost_FOUND)

set(MPIR_ROOT_DIR ${PROJECT_SOURCE_DIR})
set(MPIR_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(MPIR_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(MPIR_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

# constituent library headers
set(MTL4_INCLUDE_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/mtl4)
set(VERSION_INCLUDE_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/version)

add_definitions(-D UNIVERSAL_ENABLE_TEST=OFF)

include_directories(${MPIR_INSTALL_INCLUDE_DIR})
include_directories(${MTL4_INCLUDE_HEADERS_DIR})
include_directories(${VERSION_INCLUDE_HEADERS_DIR})

enable_testing()
include(CTest)

# Universal is a C++ header-only library, so we do not need to build anything
# if you do add this line, you will get all the Universal regression tests,
# playground, education, applications, and command line utilities.
# You can only add this build subdirectory to ONE and only ONE project
# within the IR workspace. Multiple includes will yield multiple definitions
# of build, install, and uninstall targets.
add_subdirectory(${MPIR_ROOT_DIR}/ext/stillwater-sc/universal build_universal) 

# MTL4 is a C++ header-only library, so we do not need to build anything
add_subdirectory(${MPIR_ROOT_DIR}/ext/stillwater-sc/mtl4 build_mtl4) 

add_subdirectory(src)
add_subdirectory(test)
