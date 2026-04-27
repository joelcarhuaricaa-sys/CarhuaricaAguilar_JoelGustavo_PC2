#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <string>
#include <list>

struct TrieNode {
    TrieNode* children[26];
    bool isWord;
    TrieNode();
};

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words);

private:
    void backtracking(int r, int c, TrieNode* node, std::string word, 
                      std::vector<std::vector<char>>& board, std::list<std::string>& foundList, 
                      int ROWS, int COLS);
};

#endif