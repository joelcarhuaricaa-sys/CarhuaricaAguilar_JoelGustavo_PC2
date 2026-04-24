cmake_minimum_required(VERSION 3.10)
project(CarhuaricaAguilar_JoelGustavo_PC2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Incluir directorios de cabeceras (.h)
include_directories(include)

# 2. Fuentes comunes
set(COMMON_SOURCES src/Solution.cpp)