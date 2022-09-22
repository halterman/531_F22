cmake_minimum_required(VERSION 3.11)
project(loopinvar)

# C++20
set(CMAKE_CXX_STANDARD 20)

# Adjust the warning level to high
add_compile_options(-Wall -Wextra)

# Add 'run' target to makefile
add_custom_target(run
    COMMAND loopinvar
    DEPENDS loopinvar
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

add_executable(loopinvar loopinvar.cpp)

