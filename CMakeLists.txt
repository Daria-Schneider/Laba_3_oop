cmake_minimum_required(VERSION 3.10)
project(Laba3_OOP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.0
)
FetchContent_MakeAvailable(googletest)

set(MAIN_SOURCE
    src/main.cpp
)

set(LIB_SOURCES
    src/point.cpp
    src/vector-points.cpp
    src/vector-figure.cpp
    src/figure.cpp
    src/triangle.cpp
    src/square.cpp
    src/rectangle.cpp
)

add_executable(Laba3_OOP ${MAIN_SOURCE} ${LIB_SOURCES})
target_include_directories(Laba3_OOP PRIVATE include)
target_compile_features(Laba3_OOP PRIVATE cxx_std_20)

set(TEST_SOURCES
    tests/test_point.cpp
    tests/test_figures.cpp
    tests/test_vectors.cpp
    tests/main_test.cpp
)
add_executable(run_tests ${TEST_SOURCES} ${LIB_SOURCES})
target_include_directories(run_tests PRIVATE include)
target_compile_features(run_tests PRIVATE cxx_std_20)
target_link_libraries(run_tests PRIVATE gtest_main)

enable_testing()
add_test(NAME GeometryTests COMMAND run_tests)