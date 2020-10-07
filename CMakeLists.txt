cmake_minimum_required(VERSION 3.5)

project(QWatch LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Network Svg Multimedia MultimediaWidgets REQUIRED)

file(GLOB MAIN_SRC "src/*.[hc]pp")

add_executable(QWatch ${MAIN_SRC} res.qrc)

# Don't show console window under windows
if (WIN32)
	target_link_options(QWatch PRIVATE -mwindows)
endif ()

target_link_libraries(QWatch PRIVATE Qt5::Widgets Qt5::Network Qt5::Svg Qt5::Multimedia Qt5::MultimediaWidgets)