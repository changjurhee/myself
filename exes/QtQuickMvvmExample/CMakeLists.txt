cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

project(QtQuickMvvmExample)

SET(QT_INSTALLED_PATH "/Users/changjurhee/Qt5.7.0/5.7/clang_64")
SET(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${QT_INSTALLED_PATH} CACHE_PATH "")

# This code will enable the auto MOC, UIC and RCC feature
# See https://cmake.org/cmake/help/v3.9/manual/cmake-qt.7.html

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Qml Quick Widgets  REQUIRED)

include_directories(${Qt5Widgets_INCLUDES})
#include_directories(${Qt5Declarative_INCLUDES})

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(SRC
    main.cpp

    Model/MainModel.h
    ViewModel/MainViewModel.h
    qmlapplicationviewer/qmlapplicationviewer.cpp
    qmlapplicationviewer/qmlapplicationviewer.h
)

set(RESOURCES
    
)

set(OTHERS
	qml/QtQuickMvvmExample/MainView.qml
	qml/QtQuickMvvmExample/Controls/Button.qml
	qml/QtQuickMvvmExample/Controls/TextBox.qml
)

add_executable(${PROJECT_NAME} ${SRC} ${RESOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Qml Qt5::Quick Qt5::Widgets)

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
