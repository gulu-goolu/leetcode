cmake_minimum_required(VERSION 3.14)
project(leetcode)

add_subdirectory(quick-sort)
add_subdirectory(reverse-words-in-a-string)
add_subdirectory(3sum)
add_subdirectory(reorder-list)
add_subdirectory(recover-a-tree-from-preorder-traversal)
add_subdirectory(remove-nth-node-from-end-of-list)

# 自动为以 solution 开头的 .cpp 文件创建 target
file(GLOB lc_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "lc*/solution*.cpp")
foreach (lc_file ${lc_files})
    get_filename_component(problem ${lc_file} DIRECTORY)
    get_filename_component(solution ${lc_file} NAME_WLE)
    add_executable("${problem}_${solution}" ${lc_file})
endforeach ()