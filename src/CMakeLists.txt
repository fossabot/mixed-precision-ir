cmake_minimum_required(VERSION 3.22)
project(ir)

add_subdirectory(version)
add_subdirectory(quadratic)
add_subdirectory(multifile)
add_subdirectory(luir)

# bring in Universal build/install/uninstall targets
# so that you can experiment/use all the regression and utility code available in Universal
add_subdirectory(universal)

# semver CLI command
set(app_name semver)
set(SOURCE_FILES semver.cpp)
add_executable(${app_name} ${SOURCE_FILES})
set(folder "Tools")
set_target_properties(${app_name} PROPERTIES FOLDER ${folder})

target_link_libraries(semver versionLib)
install(TARGETS semver DESTINATION ${MPIR_INSTALL_BIN_DIR})
