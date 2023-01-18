#pragma once
#include <iostream>
#include <string>
const int ALPHABET_SIZE = (26);
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};
TrieNode* getNewNode(void);
void insert(TrieNode*, std::string);
bool search(TrieNode*, std::string);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, std::string, int depth = 0);
void findWordbyPrefInner(TrieNode* root, std::string currPrefix);
int findWordbyPref(TrieNode* root, const std::string& prefix);

