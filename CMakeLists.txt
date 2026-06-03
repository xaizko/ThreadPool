cmake_minimum_required(VERSION 4.3.2)
project(ThreadPool LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -g)

add_executable(threadpool_test
	src/main.cpp
	src/ThreadPool.cpp
)
