cmake_minimum_required(VERSION 3.10)
project(wordle-terminal-based)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(wordle
    src/main.cpp
    src/game.cpp
    src/utils.cpp
)
