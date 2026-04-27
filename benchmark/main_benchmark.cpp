#include <iostream>
#include <chrono>
#include <vector>
#include <string> // Importante incluirlo explícitamente
#include "../include/Solution.h"

void run_benchmark() {
    Solution sol;
    
    // 1. Definición del escenario de prueba (Stress Test)
    // Tablero de 10x10 lleno de la letra 'a' para maximizar la recursión
    std::vector<std::vector<char>> board(10, std::vector<char>(10, 'a'));
    
    // Diccionario de prueba: 500 variantes de la palabra "aaaaa"
    std::vector<std::string> words;
    for(int i = 0; i < 500; ++i) {
        words.push_back(std::string(5, 'a')); 
    }

    std::cout << "===========================================" << std::endl;
    std::cout << "   BENCHMARK DE RENDIMIENTO: findWords     " << std::endl;
    std::cout << "===========================================" << std::endl;
    
    // 2. Medición de tiempo con alta precisión
    auto start = std::chrono::high_resolution_clock::now();
    
    sol.findWords(board, words);
    
    auto end = std::chrono::high_resolution_clock::now();
    
    // 3. Cálculo y formato de resultados
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Detalles de la prueba:" << std::endl;
    std::cout << " - Tamano del tablero: " << board.size() << "x" << board[0].size() << std::endl;
    std::cout << " - Palabras procesadas: " << words.size() << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "TIEMPO DE EJECUCION: " << duration.count() << " ms" << std::endl;
    std::cout << "===========================================" << std::endl;
}

int main() {
    run_benchmark();
    return 0;
}