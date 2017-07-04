project(exe3)

cmake_policy(SET CMP0016 NEW)


set(SRC
    main.cpp

    traits/accum0.hpp
    traits/accum1.hpp
    traits/accum2.hpp
    traits/accum3.hpp
    traits/accum5.hpp
    traits/accum6.hpp
    traits/accum7.hpp
    traits/accum8.hpp
    traits/accumtraits2.hpp
    traits/accumtraits3.hpp
    traits/accumtraits4.hpp
    traits/sumpolicy1.hpp
    traits/sumpolicy2.hpp
    traits/sumpolicy3.hpp
    traits/sizeof.cpp
    traits/elementtype.cpp
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
