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

    int ROWS = board.size();
    int COLS = board[0].size();
    std::list<std::string> foundList; 

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            backtracking(r, c, root, "", board, foundList, ROWS, COLS);
        }
    }

    return std::vector<std::string>(foundList.begin(), foundList.end());
}
void Solution::backtracking(int r, int c, TrieNode* node, std::string word, 
                             std::vector<std::vector<char>>& board, std::list<std::string>& foundList, 
                             int ROWS, int COLS) {
    
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] == '#' || !node->children[board[r][c] - 'a']) {
        return;
    }