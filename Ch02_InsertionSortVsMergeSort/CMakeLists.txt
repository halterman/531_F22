cmake_minimum_required(VERSION 3.11.0)
project(insertion_merge_sorts VERSION 0.1.0)

set(CXX_STANDARD 20)
add_compile_options(-Wall -Wextra)
add_executable(insertion_merge_sorts 
               insertion_merge_sorts.cpp
               stopwatch.cpp)
