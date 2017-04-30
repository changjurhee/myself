project(ATM)

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

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
