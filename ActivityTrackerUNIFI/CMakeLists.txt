cmake_minimum_required(VERSION 3.17)
project(ActivityTrackerUNIFI)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(ActivityTrackerUNIFI ActivityTrackerApp.cpp ActivityTrackerApp.h MainMenu.cpp MainMenu.h)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
