cmake_minimum_required(VERSION 3.27)
project(CountdownSort)

set(CMAKE_CXX_STANDARD 17)

add_executable(CountdownSort main.cpp
        countdownsort.h
        mymap.h
)
