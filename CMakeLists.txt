cmake_minimum_required(VERSION 2.6)

project(myself)
set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_PATCH "0")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

add_definitions(-DDEF_RET_YES)

include_directories(${PROJECT_SOURCE_DIR}/inc)
link_directories(${PROJECT_SOURCE_DIR}/external/lib)

message("Binary Tree path : ${PROJECT_BINARY_DIR}")

add_subdirectory(libssrc)
add_subdirectory(dlls)
add_subdirectory(exes)
