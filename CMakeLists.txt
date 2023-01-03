cmake_minimum_required(VERSION 3.22)

project(mixed-precision-ir)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(MPIR_ROOT_DIR ${PROJECT_SOURCE_DIR})
set(MPIR_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(MPIR_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(MPIR_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

# constituent library headers
set(IR_INCLUDE_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/ir)
set(VERSION_INCLUDE_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/version)

include_directories(${MPIR_INSTALL_INCLUDE_DIR})
include_directories(${IR_INCLUDE_HEADERS_DIR})
include_directories(${VERSION_INCLUDE_HEADERS_DIR})

add_subdirectory(src)
add_subdirectory(test)
