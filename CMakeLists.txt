cmake_minimum_required(VERSION 3.14)
project(leetcode)

set(CMAKE_EXECUTABLE_OUTPUT_PATH bin)

set (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/module)

find_package(GoogleTest)

function (lc_add_executable target)
    add_executable (${target} ${ARGN})
    target_link_libraries (${target} gtest_main)
endfunction ()

add_subdirectory(problems)

add_subdirectory(reverse-words-in-a-string)
add_subdirectory(reorder-list)
add_subdirectory(recover-a-tree-from-preorder-traversal)
add_subdirectory(remove-nth-node-from-end-of-list)


add_subdirectory(interview)