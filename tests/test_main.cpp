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

void test_sin_coincidencias() {
    Solution sol;
    // Tablero con letras que no forman nada útil
    std::vector<std::vector<char>> board = {{'x','y'},{'z','w'}};
    std::vector<std::string> words = {"hola", "mundo"};
    
    std::vector<std::string> res = sol.findWords(board, words);
    
    // El resultado debe ser una lista vacía
    assert(res.empty());
    std::cout << "[PASSED] Test Sin Coincidencias" << std::endl;
}
void test_palabra_larga(){
    Solution sol;
    // Tablero de una sola fila
    std::vector<std::vector<char>> board = {{'a','b','c'}};
    // Palabra de 4 letras (imposible de formar en un tablero de 3 celdas)
    std::vector<std::string> words = {"abcd"}; 
    
    std::vector<std::string> res = sol.findWords(board, words);
    
    // Debe retornar vacío y no causar un "out of bounds" (desbordamiento)
    assert(res.empty());
    std::cout << "[PASSED] Test Palabra Fuera de Limites" << std::endl;
}

int main() {
    std::cout << "--- Ejecutando Pruebas Unitarias ---" << std::endl;
    test_caso_basico();
    test_sin_coincidencias();  
    test_palabra_larga();      
    std::cout << "--- Todas las pruebas pasaron con exito ---" << std::endl;
    return 0;
}