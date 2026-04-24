cmake_minimum_required(VERSION 3.10)
project(CarhuaricaAguilar_JoelGustavo_PC2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Incluir directorios de cabeceras (.h)
include_directories(include)

# 2. Fuentes comunes
set(COMMON_SOURCES src/Solution.cpp)

# 3. Ejecutable Principal (Demo)
add_executable(demo_p2 demos/main.cpp ${COMMON_SOURCES})

#4. Ejecutable de Benchmark (Medición de rendimiento)
add_executable(benchmark_p2 benchmark/main_benchmark.cpp ${COMMON_SOURCES})

#6. Tests (Si decides añadirlos luego)
#6. Tests
add_executable(tests_p2 tests/test_main.cpp ${COMMON_SOURCES})