#include <string>
#include <list>

struct TrieNode {
    TrieNode* children[26];
    bool isWord;
    TrieNode();
};