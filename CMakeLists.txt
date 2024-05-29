cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Test)

set(PRINT_VERSION_MAJOR 0)
set(PRINT_VERSION_MINOR 1)
set(PRINT_VERSION_PATCH 0)
set(PRINT_VERSION_TWEAK 0)
set(PRINT_VERSION\${PRINT_VERSION_MAJOR}.${PRINT_VERSION_MINOR}.${PRINT_VERSION_PATCH}.${PRINT_VERSION_TWEAK})
set(PRINT_VERSION_STRING "v${PRINT_VERSION}")

enable_testing()
add_subdirectory(third-party)
add_executable(test_app tests/test.cpp)
target_link_libraries(test_app gtest_main gmock_main)
add_test(NAME test_app COMMAND test_app)

include(CPack.cmake)
