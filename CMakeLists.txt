cmake_minimum_required(VERSION 3.16)

project(imageProc VERSION 1.0.0 LANGUAGES CXX)

# Path to qt6 basebuild
set(CMAKE_PREFIX_PATH "/Users/thierry/qt6-build-debug/" ${CMAKE_PREFIX_PATH})

#
# In case that the previous link doesn't work
#
# cmake -DCMAKE_PREFIX_PATH="/Users/thierry/Desktop/qtbase/qt6base-build/" /Users/thierry/Desktop/imageProc/ 
#

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Network)
find_package(Qt6 REQUIRED COMPONENTS HttpServer)

qt_standard_project_setup()

add_subdirectory(src/app)