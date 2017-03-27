project(exe1)

cmake_policy(SET CMP0016 NEW)


set(SRC
    main.cpp
)

set(RESOURCES
	
)

set(OTHERS
   ${BOOST_INCLUDE_DIR}
)

add_executable(${PROJECT_NAME} ${SRC} ${RESOURCES} ${OTHERS})

target_link_libraries(${PROJECT_NAME} dll1)

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
