project(boostTest)

cmake_policy(SET CMP0016 NEW)

set(SRC
	main.cpp
)

set(RESOURCES
	test.json
)

set(OTHERS
	${BOOST_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} ${SRC} ${RESOURCES} ${OTHERS})
target_link_libraries(${PROJECT_NAME} dll1 ${Boost_LIBRARIES})
add_custom_command(TARGET ${PROJECT_NAME}
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                   ${CMAKE_CURRENT_SOURCE_DIR}/test.json
		   $<TARGET_FILE_DIR:${PROJECT_NAME}>/test.json
                   COMMENT "Copy *.json into binaries folder"
                   )
install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)

