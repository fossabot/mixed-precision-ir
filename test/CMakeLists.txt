cmake_minimum_required(VERSION 3.22)
project(mpir_tests)

add_subdirectory(lib/googletest)

include_directories(${VERSION_INCLUDE_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/mpir_tests.cpp)


add_executable(mpir_tests ${SOURCE_FILES})
target_link_libraries(mpir_tests semver gtest)
install(TARGETS mpir_tests DESTINATION bin)
