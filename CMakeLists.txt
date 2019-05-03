# General CMake Config #
cmake_minimum_required(VERSION 2.6)
project(HBTCPServer)

# Add all files needed for compilation to sources variable
file(GLOB_RECURSE sources src/main.cpp src/server/*cpp src/server/*.h)

# Add files to executable
add_executable(test_app ${sources})

# Adding Librarires #

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-lboost_system -lboost_thread")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(BOOST_ROOT "/home/ben/libs/boost_1_70_0/")
set(BOOST_INCLUDEDIR "/home/ben/libs/boost_1_70_0/boost")
set(BOOST_LIBRARYDIR "/home/ben/libs/boost_1_70_0/stage/lib")

FIND_PACKAGE(Boost 1.70.0 REQUIRED COMPONENTS system)

IF(Boost_FOUND)
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
	LINK_DIRECTORIES(${BOOST_LIBRARYDIR})

	add_definitions(-DBOOST_ALL_NO_LIB)
ENDIF(Boost_FOUND)

IF(WIN32)
	target_link_libraries(test_app ws2_32)
	target_link_libraries(test_app wsock32)
ENDIF(WIN32)

IF(UNIX)
	target_link_libraries(test_app "-lboost_system -lboost_thread -lpthread")
ENDIF(UNIX)

include_directories (${PROJECT_SOURCE_DECLARATION_DIRECTORY})

