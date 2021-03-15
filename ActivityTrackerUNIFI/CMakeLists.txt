cmake_minimum_required(VERSION 3.17)
project(ActivityTrackerUNIFI)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)
find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES ActivityTrackerApp.cpp ActivityTrackerApp.h MainMenu.cpp MainMenu.h Activity.cpp Activity.h ActivityView.cpp ActivityView.h Subject.h Observer.h AddNewActivityView.cpp AddNewActivityView.h ActivityTrackerController.cpp ActivityTrackerController.h DailyActivityRegister.cpp DailyActivityRegister.h DailyActivityRegisterView.cpp DailyActivityRegisterView.h ActivityTrackerHistory.cpp ActivityTrackerHistory.h Date.cpp Date.h ActivityTime.cpp ActivityTime.h WrongTimeFormatException.cpp WrongTimeFormatException.h)
add_executable(ActivityTrackerUNIFI ActivityTrackerApp.cpp ActivityTrackerApp.h MainMenu.cpp MainMenu.h Activity.cpp Activity.h ActivityView.cpp ActivityView.h Subject.h Observer.h AddNewActivityView.cpp AddNewActivityView.h ActivityTrackerController.cpp ActivityTrackerController.h DailyActivityRegister.cpp DailyActivityRegister.h DailyActivityRegisterView.cpp DailyActivityRegisterView.h ActivityTrackerHistory.cpp ActivityTrackerHistory.h Date.cpp Date.h ActivityTime.cpp ActivityTime.h WrongTimeFormatException.cpp WrongTimeFormatException.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
