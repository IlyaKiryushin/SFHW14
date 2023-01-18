#include <iostream>
#include "Trie.h"
TrieNode* getNewNode(void)
{
    struct TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;
    return pNode;
}
void insert(TrieNode* root, std::string key)
{
    TrieNode* node = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            node->children[index] = getNewNode();
        node = node->children[index];
    }
    node->isEndOfWord = true;
}
bool search(struct TrieNode* root, std::string key)
{
    struct TrieNode* node = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;
        node = node->children[index];
    }
    return (node != nullptr && node->isEndOfWord);
}
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}
TrieNode* remove(TrieNode* root, std::string key, int depth)
{
    if (!root)
        return nullptr;
    if (depth == key.size()) {
        if (root->isEndOfWord)
            root->isEndOfWord = false;
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }
        return root;
    }
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }
    return root;
}
void findWordbyPrefInner(TrieNode* currentNode, std::string currPrefix)
{
    if (currentNode->isEndOfWord)
        std::cout << currPrefix << std::endl;

    for (size_t i = 0; i < ALPHABET_SIZE; i++)
        if (currentNode->children[i]) {
            char child = 'a' + i;
            findWordbyPrefInner(currentNode->children[i], currPrefix + child);
        }
}
int findWordbyPref(TrieNode* root, const std::string& prefix)
{
    struct TrieNode* node = root;

    for (size_t i = 0; i < prefix.length(); i++)
    {
        int index = prefix[i] - 'a';
        if (!node->children[index]) 
            return -1;
        node = node->children[index];
    }
    if (isEmpty(node))
    {
        std::cout << prefix << std::endl;
        return 0;
    }
    findWordbyPref(node, prefix);
    return 1;
}