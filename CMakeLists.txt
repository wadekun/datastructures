cmake_minimum_required(VERSION 3.7)
project(datastructures)

set(CMAKE_C_STANDARD 99)

set(LIST_TABLE library.c library.h list/ListTable.c)
set(LINKED_LIST library.c library.h list/LinkedList.c)

add_library(datastructures ${SOURCE_FILES} list/LinkedList.c)
add_executable(list_table ${LIST_TABLE})
add_executable(linkedList ${LINKED_LIST})