project(aoc)

cmake_minimum_required(VERSION 2.8)

enable_testing()

####################################################
# Set the C++ Standard to be used (Default to C++11)
####################################################
set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

####################################################################
# Set Compiler flags
####################################################################
IF (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++${CXX_STANDARD}")
ELSEIF (MSVC)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
ENDIF()

include_directories("${CMAKE_SOURCE_DIR}/include")

####################################################
# Add Unit Tests file names (without .cpp extension)
####################################################
list(APPEND UNIT_TESTS
    Day1
    Day2
    Day3
    Day4
    Day5
    Day6
    Day7
    Day8
    Day9
    Day10
    Day11
    Day12
    Day13
    Day14
    Day15
    Day16
)

list(APPEND SOURCES
    Day1
    Day2
    Day3
    Day4
    Day5
    Day6
    Day7
    Day8
    Day9
    Day10
    Day11
    Day12
    Day13
    Day14
    Day15
    Day16
)

foreach(SOURCE ${SOURCES})
    list(APPEND SOURCE_FILES
        "${CMAKE_SOURCE_DIR}/src/${SOURCE}.cpp"
    )
endforeach()


####################################################
# Create executable for each test
####################################################
foreach(TEST ${UNIT_TESTS})
    add_executable(${TEST} "${CMAKE_SOURCE_DIR}/test/${TEST}.cpp" "${CMAKE_SOURCE_DIR}/src/${TEST}.cpp")

    add_test(${TEST} ${TEST})
endforeach()

add_executable("aoc" "${CMAKE_SOURCE_DIR}/src/Runner.cpp" ${SOURCE_FILES})