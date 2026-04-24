#include "Solution.h"

// Constructor: Inicializa los 26 hijos como nulos
TrieNode::TrieNode() {
    isWord = false;
    for(int i = 0; i < 26; i++) {
        children[i] = nullptr; 
    }
}
std::vector<std::string> Solution::findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
    // Creamos la raíz del Trie
    TrieNode* root = new TrieNode();

    // Insertamos cada palabra en el Trie
    for (const std::string& w : words) { 
        TrieNode* cur = root;
        for (char c : w) {
            int idx = c - 'a'; // Convertimos letra a índice 0-25
            if (!cur->children[idx]) {
                cur->children[idx] = new TrieNode();
            }
             cur = cur->children[idx];
        }
        cur->isWord = true; // Marcamos el final de una palabra válida
    }

    // Por ahora retornamos vacío para que el commit sea solo de la estructura
    return {}; 
}