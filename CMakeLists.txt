cmake_minimum_required(VERSION 3.10)

# Nama project
project(WordleTerminal)

# Tentukan standar C++`
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tambahkan executable dari source file
add_executable(wordle
    src/main.cpp
)