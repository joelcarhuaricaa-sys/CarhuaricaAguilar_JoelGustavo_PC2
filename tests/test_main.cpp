#include <iostream>
#include <cassert>     // Para usar assert()
#include <algorithm>   // Para usar std::find
#include <vector>
#include "../include/Solution.h"

void test_caso_basico() {
    Solution sol;
    std::vector<std::vector<char>> board = {{'a','b'},{'c','d'}};
    std::vector<std::string> words = {"ab", "ac", "abcd", "dcba"};
    
    std::vector<std::string> res = sol.findWords(board, words);
    
    // Verificamos que encuentre exactamente 2 palabras ("ab" y "ac")
    // "abcd" no se puede porque 'd' no está al lado de 'b' o 'c' en este tablero
    assert(res.size() == 2);
    assert(std::find(res.begin(), res.end(), "ab") != res.end());
    assert(std::find(res.begin(), res.end(), "ac") != res.end());
    std::cout << "[PASSED] Test Caso Basico" << std::endl;
}

void test_sin_coincidencias();
void test_palabra_larga();

int main() {
    std::cout << "--- Iniciando Pruebas Unitarias ---" << std::endl;
    
    test_caso_basico(); // <--- Ahora sí la llamamos
    
    std::cout << "--- Pruebas finalizadas ---" << std::endl;
    return 0;
}