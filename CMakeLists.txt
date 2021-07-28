cmake_minimum_required(VERSION 3.14)
project(leetcode)

set(CMAKE_EXECUTABLE_OUTPUT_PATH bin)

set (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/module)

find_package(googletest)

add_subdirectory(problems)

add_subdirectory(reverse-words-in-a-string)
add_subdirectory(reorder-list)
add_subdirectory(recover-a-tree-from-preorder-traversal)
add_subdirectory(remove-nth-node-from-end-of-list)


add_subdirectory(interview)