cmake_minimum_required(VERSION 3.5)
project(TreeModelView VERSION 0.1.0)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
link_libraries(Qt5::Widgets)

file(GLOB ALL_FILE "*.h" "*.cpp")
add_executable(TreeModelView ${ALL_FILE})
