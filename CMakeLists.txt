cmake_minimum_required(VERSION 3.13)
project(CenterDot)

# version number
set (CENTER_DOT_VERSION_MAJOR 1)
set (CENTER_DOT_VERSION_MINOR 1)
set (CENTER_DOT_VERSION_REVISION 0)

set(CMAKE_CXX_STANDARD 14)

configure_file (
    "${PROJECT_SOURCE_DIR}/src/version_number.h.in"
    "${PROJECT_SOURCE_DIR}/src/version_number.h"
)

# call find_package for required Qt packages
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

set(CMAKE_AUTOMOC ON) # Handle the Qt MOC (Meta object code) generation automatically
set(CMAKE_AUTOUIC ON) # Handle the Qt UIC (Forms) code generation automatically
set(CMAKE_AUTORCC ON) # Handle the Qt RCC (Resources) code generation automatically

# set directory containing Qt includes and libraries for MinGW
if(WIN32)
    set(CMAKE_PREFIX_PATH "C:\\Dev\\Qt\\5.12.2\\mingw73_64\\lib\\cmake") # To be modified pointing to Qt CMake libs dir
endif()

# compiler flags
# note: option -D__NO_INLINE__ necessary due to MinGW bug, can maybe removed later
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mwindows -D__NO_INLINE__")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} -Wall")

# source files to be compiled
set(SOURCE_FILES
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/settingsdata.h
    src/settingsdialog.cpp
    src/settingsdialog.h
    src/version_number.h
    src/version_number.h.in
    src/winkeyboardhook.cpp
    src/winkeyboardhook.h)

# set exectuable name
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

# link against Qt libraries
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Gui)