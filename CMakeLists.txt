cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME myself)
project(${PROJECT_NAME})

If (NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Debug … force)
endif()

set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_PATCH "0")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

add_definitions(-DDEF_RET_YES)

#--
# Define project sources and includes
#--

include_directories(${PROJECT_SOURCE_DIR}/inc)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.cpp)

set(CMAKE_CXX_STANDARD 11)

#link_directories(${PROJECT_SOURCE_DIR}/external/lib)

#--
# Normal Libraries & Executables
#--

message("Binary Tree path : ${PROJECT_BINARY_DIR}") 
message(“CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}”)
 
add_subdirectory(libssrc)                           
add_subdirectory(dlls)
add_subdirectory(exes)                              

add_library(${PROJECT_NAME}_lib ${SRC_FILES})
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

#-- 
# testing
#--

option(BUILD_TESTS "Build all tests." OFF)

if(BUILD_TESTS)
	add_subdirectory(ext/gtest-1.8.0)
	enable_testing()
	include_directories(${gtest_SOURCE_DIR}/inc ${gtest_SOURCE_DIR})

	#--
	# unit tests
	#--

	add_executable(runUnitTests ${TEST_SRC_FILES})
	target_link_libraries(runUnitTests ${PROJECT_NAME}_lib)

	add_test(UnitTests runUnitTests)

	set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/.travis/cmake)

	if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
		include(CodeCoverage)
		setup_target_for_coverage(${PROJECT_NAME}_coverage runUnitTests coverage)

		SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
		SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
	endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"

endif()
	
	
	
