class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() : isEnd(false) {}
};

class Trie {
private:
    TrieNode* root;

    bool searchRecursive(TrieNode* node, const string& word, int index) {
        if (!node) return false;
        if (index == word.size()) return node->isEnd;
        return searchRecursive(node->children[word[index]], word, index + 1);
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch])
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool searchIterative(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch])
                return false;
            node = node->children[ch];
        }
        return node->isEnd;
    }

    
};

