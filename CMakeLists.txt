# General CMake Config #
cmake_minimum_required(VERSION 2.6)
project(HBTCPServer)


# Add all files needed for compilation to sources variable
file(GLOB_RECURSE sources src/main.cpp src/server/*cpp src/server/*.h)

# Add files to executable
add_executable(test_app ${sources})

# Adding Librarires #

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(BOOST_ROOT "D:/src/libs/boost_1_69_0")
set(BOOST_INCLUDEDIR "D:/src/libs/boost_1_69_0/boost")
set(BOOST_LIBRARYDIR "D:/src/libs/boost_1_69_0/stage/lib")

FIND_PACKAGE(Boost 1.69.0 REQUIRED COMPONENTS system)

IF(Boost_FOUND)
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
	LINK_DIRECTORIES(${BOOST_LIBRARYDIR})

	add_definitions(-DBOOST_ALL_NO_LIB)
ENDIF(Boost_FOUND)

include_directories (${PROJECT_SOURCE_DECLARATION_DIRECTORY})

