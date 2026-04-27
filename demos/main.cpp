#include <iostream>
#include <vector>
#include <string>
#include "../include/Solution.h"

int main() {
    Solution sol;
    
    // Tablero de prueba
    std::vector<std::vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    
    // Palabras a buscar
    std::vector<std::string> words = {"oath","pea","eat","rain"};

    // Ejecución del algoritmo
    std::vector<std::string> result = sol.findWords(board, words);

    std::cout << "--- Resultados de la Busqueda ---" << std::endl;
    if (result.empty()) {
        std::cout << "No se encontraron palabras." << std::endl;
    } else {
        for (const std::string& s : result) {
            std::cout << "[ENCONTRADA]: " << s << std::endl;
        }
    }

    return 0;
}