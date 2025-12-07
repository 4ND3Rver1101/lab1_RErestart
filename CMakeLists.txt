cmake_minimum_required(VERSION 3.31.6)
project(lab1_RErestart)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(lab1_RErestart main.cpp
     
		bubble_method.cpp
		bubble_method.h
		data.h
		qsort_method.h
		qsort_method.cpp
		Test.cpp
		Test.h)