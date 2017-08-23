cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

project(openglunderqml)

SET(QT_INSTALLED_PATH "/Users/changjurhee/Qt5.7.0/5.7/clang_64")
SET(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${QT_INSTALLED_PATH} CACHE_PATH "")

# This code will enable the auto MOC, UIC and RCC feature
# See https://cmake.org/cmake/help/v3.9/manual/cmake-qt.7.html

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Qml Quick REQUIRED)

set(SRC
    main.cpp
    squircle.cpp

    squircle.h
)

set(RESOURCES
    openglunderqml.qrc	
)

set(OTHERS
)

add_executable(${PROJECT_NAME} ${SRC} ${RESOURCES} ${OTHERS})
target_link_libraries(${PROJECT_NAME} Qt5::Qml Qt5::Quick)

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
