cmake_minimum_required(VERSION 3.21)
project(apue_test C)
set(CMAKE_C_STANDARD 11)

#include_directories(/usr/local/include)
include_directories(apue.3e/include)
link_libraries(/usr/local/lib/libapue.a)

file(GLOB files ${PROJECT_SOURCE_DIR}/*.c)
foreach (file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
endforeach ()
