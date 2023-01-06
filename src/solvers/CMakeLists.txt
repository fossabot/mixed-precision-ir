cmake_minimum_required(VERSION 3.22)
project(solvers CXX)

# Universal is a C++ header-only library, so we do not need to build anything
include_directories(${MPIR_ROOT_DIR}/ext/stillwater-sc/universal)
# MTL4 is a C++ header-only library, so no need to build anything either
include_directories(${MPIR_ROOT_DIR}/ext/stillwater-sc/mtl4)

# source files that make up the command
set(SOURCE_FILES
)

add_executable(matinverse gauss_jordan.cpp)
set(folder "Solvers")
set_target_properties(matinverse PROPERTIES FOLDER ${folder})

#add_executable(cholesky cholesky.cpp)
#set(folder "Solvers")
#set_target_properties(cholesky PROPERTIES FOLDER ${folder})

# add libraries if you need them
#target_link_libraries(matinverse required-library1 required-library2)
install(TARGETS matinverse DESTINATION ${MPIR_INSTALL_BIN_DIR})
#install(FILES my-consolidated-include.hpp DESTINATION ${MPIR_INSTALL_INCLUDE_DIR})
