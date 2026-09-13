
class Node {
public:
    Node* child[26]{};
    int end = 0;
    int used = 0;
    Node() {

    }
};
 class Trie {
public:
    Node* root = new Node;
    Trie() {
        
    }
    
    void insert(string word) {
        auto node = root;
        for (char c : word) {
            if (!node->child[c - 'a']) {
                node->child[c - 'a'] = new Node;
            }
            node = node->child[c - 'a'];
        }
        node->end = 1;
    }
    
    bool search(string word) {
        auto node{root};
        for (char c : word) {
            if (!node->child[c - 'a']) return false;
            node = node->child[c - 'a'];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        auto node{root};
        for (char c : prefix) {
            if (!node->child[c - 'a']) return false;
            node = node->child[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */