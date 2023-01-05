cmake_minimum_required(VERSION 3.22)
project(ir)

add_subdirectory(version)
# simple starter skeleton for projects that use the Universal Number System library
add_subdirectory(universal)
# a more complicated example project that consists of multiple source files
add_subdirectory(multifile)
# a purposefull example of a mixed-precision experiment for the quadratic equation
add_subdirectory(quadratic)

# a full blown mixed-precision algorithm development and optimization project targeting the Gaussian Elimination algorithm
add_subdirectory(luir)

# mixed-precision algorithm development and optimization project targeting matrix inversion algorithms
add_subdirectory(solvers)

# semver CLI command
set(app_name semver)
set(SOURCE_FILES semver.cpp)
add_executable(${app_name} ${SOURCE_FILES})
set(folder "Tools")
set_target_properties(${app_name} PROPERTIES FOLDER ${folder})

target_link_libraries(semver versionLib)
install(TARGETS semver DESTINATION ${MPIR_INSTALL_BIN_DIR})
