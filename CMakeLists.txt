cmake_minimum_required(VERSION 3.20)
project(2LinkedList)
add_executable(2LinkedList main.cpp listNode.h listNode.cpp list.h list.cpp)

add_subdirectory(Catch2 Catch2-build)
add_executable(2LinkedListTests test.cpp listNode.h listNode.cpp list.h list.cpp)
target_link_libraries(2LinkedListTests PRIVATE Catch2::Catch2)