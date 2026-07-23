class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool end = false;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        return search(word, root);
    }

    bool search(string word, TrieNode* start) {
        TrieNode* curr = start;
        for (unsigned i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto m : curr->children) {
                    if (i == word.size() - 1 && m.second->end) {
                        return true;
                    } else if (search(word.substr(i + 1), m.second)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (curr->children.find(c) == curr->children.end()) {
                    return false;
                }
                curr = curr->children[c];
            }
        }
        return curr->end;
    }

    TrieNode* root;
};
