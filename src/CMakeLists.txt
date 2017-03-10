set(CMAKE_C_FLAGS “-Wall -g”)
file(GLOB SRCS *.cpp)
add_executable(myself ${SRCS})
