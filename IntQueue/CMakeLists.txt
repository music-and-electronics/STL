cmake_minimum_required(VERSION 3.14)
project(IntQueue C)

set(CMAKE_C_STANDARD 99)

add_executable(IntQueue main.c IntQueue.h IntQueue.c)