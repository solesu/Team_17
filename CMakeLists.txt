cmake_minimum_required (VERSION 2.6)
project (Team_17)
set(CMAKE_CXX_FLAGS "-O3 -W -Wall -pedantic -std=c++11")



add_executable(genetics source/Allele.cpp source/Population.cpp source/Random.cpp source/Simulation.cpp source/main.cpp)

# google testing
add_subdirectory(gtest)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
Include_directories (Before tclap/include)


add_executable(unitest source/Allele.cpp source/Population.cpp source/Random.cpp source/Simulation.cpp source/main.cpp test/test.cpp)
target_link_libraries(unitest gtest gtest_main)
add_test(unitest unitest)


# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
add_custom_target(doc
${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)