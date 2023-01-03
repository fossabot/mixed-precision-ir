cmake_minimum_required(VERSION 3.22)
project(ir)

add_subdirectory(version)
set(SOURCE_FILES main.cpp)

add_executable(semver ${SOURCE_FILES})
target_link_libraries(semver version)
install(TARGETS semver DESTINATION ${MPIR_INSTALL_BIN_DIR})
