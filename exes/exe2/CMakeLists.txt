project(exe2)

cmake_policy(SET CMP0016 NEW)


set(SRC
    main.cpp
)

set(RESOURCES
	
)

set(OTHERS
)

add_executable(${PROJECT_NAME} ${SRC} ${RESOURCES} ${OTHERS})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
