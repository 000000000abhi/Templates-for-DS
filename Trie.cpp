#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) 
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

    bool searchRecursive(TrieNode* node, const string& word, int index) {
        if (!node) return false;
        if (index == word.size()) return node->isEnd;
        return searchRecursive(node->children[word[index] - 'a'], word, index + 1);
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool searchIterative(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool searchRecursive(const string& word) {
        return searchRecursive(root, word, 0);
    }
};


