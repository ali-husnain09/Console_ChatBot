cmake_minimum_required(VERSION 3.30)
project(Console_ChatBot)

set(CMAKE_CXX_STANDARD 20)

add_executable(Console_ChatBot
    main.cpp
        general_discussion.cpp
        mathematical.cpp)
