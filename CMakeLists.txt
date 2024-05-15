cmake_minimum_required(VERSION 3.28)
project(ZooTycoonCPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(ZooTycoonCPP main.cpp
        src/animals/Animal.h
        src/animals/Mammal.h
        src/animals/Bird.h
        src/animals/Reptile.h
        src/zoo/Zoo.h
        src/zoo/Enclosure.h
        src/zoo/Enclosure.cpp
        src/zoo/Zoo.cpp
)
