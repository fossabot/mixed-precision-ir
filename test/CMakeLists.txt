cmake_minimum_required(VERSION 3.22)
project(mpir_tests)

add_subdirectory(${MPIR_ROOT_DIR}/ext/googletest)

include_directories(${VERSION_INCLUDE_HEADERS_DIR})
include_directories(${PROJECT_SOURCE_DIR}/ext/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/mpir_tests.cpp)


add_executable(mpir_tests ${SOURCE_FILES})
#target_link_libraries(mpir_tests semver gtest)
target_link_libraries(mpir_tests gtest)
install(TARGETS mpir_tests DESTINATION bin)
