cmake_minimum_required(VERSION 3.22)
project(ir)

add_subdirectory(version)
add_subdirectory(multifile)

# semver CLI command
set(SEMVER_SRC_FILES semver.cpp)
add_executable(semver ${SEMVER_SRC_FILES})
target_link_libraries(semver version)
install(TARGETS semver DESTINATION ${MPIR_INSTALL_BIN_DIR})

