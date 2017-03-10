project(dll1)

cmake_policy(SET CMP0042 NEW)

set(${PROJECT_NAME}_headers dll1.h)
set(${PROJECT_NAME}_sources dll1.cpp)

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_headers} ${${PROJECT_NAME}_sources})

target_link_libraries(${PROJECT_NAME} lib1)

install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib/static)
