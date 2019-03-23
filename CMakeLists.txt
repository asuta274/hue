cmake_minimum_required(VERSION 3.6)
project(hue)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories(include)

set(SRC
    src/hue/array.c
    src/hue/tensor.c
)

add_library(${PROJECT_NAME} STATIC ${SRC})

find_package(GTest REQUIRED)
add_executable(${PROJECT_NAME}_test
    tst/main.cpp
    tst/hue/array_test.cpp
    tst/hue/tensor_test.cpp
)
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)
add_test(${PROJECT_NAME}_test ${PROJECT_NAME}_test)
enable_testing()

#sandbox
add_executable(read_file sandbox/readfile.c)
add_executable(quick_select sandbox/quickselect.c)
add_executable(wiggle_sort_ii sandbox/leetcode/wiggle-sort-ii.c)
add_executable(all_pairs_short sandbox/coursera/algo41/all_pairs.c)