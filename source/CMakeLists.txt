cmake_minimum_required (VERSION 2.6)
project (Team_17_project)
set(CMAKE_CXX_FLAGS "-O3 -W -Wall -pedantic -std=c++11")

set(SOURCE_FILES source/Population.cpp source/Random.cpp source/Simulation.cpp)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories (Before tclap/include)

add_executable(Genetics source/main.cpp ${SOURCE_FILES})

# googletest
if (test)
enable_testing()
find_package(gtest)
if (NOT GTEST_FOUND)
link_directories(${CMAKE_SOURCE_DIR}/extra/lib) 
SET(GTEST_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/extra/include) 
SET(GTEST_BOTH_LIBRARIES libgtest.a libgtest_main.a)
endif(NOT GTEST_FOUND)
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/source) 
add_executable(Unittest  test/test.cpp ${SOURCE_FILES}) 
target_link_libraries(Unittest ${GTEST_BOTH_LIBRARIES} pthread) 
add_test(Team_17_project Unittest)
endif(test)

# add a target to generate API documentation with Doxygen
find_package(Doxygen) 
if (DOXYGEN_FOUND)
add_custom_target(doc
${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
COMMENT "Generating API documentation with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)
