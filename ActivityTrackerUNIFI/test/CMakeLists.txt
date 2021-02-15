cmake_minimum_required(VERSION 3.5)
project(ActivityTrackerUNIFI)

add_subdirectory(./lib/googletest-release-1.10.0)
set(gtest_SOURCE_DIR, ./lib/googletest-release-1.10.0)
include_directories(${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTest.cpp ActivityTest.cpp)
add_executable(TestActivityTrackerUNIFI ${TEST_SOURCE_FILES})
target_link_libraries(TestActivityTrackerUNIFI gtest gtest_main core)