# define SIZE 26

struct TrieNode {
    struct TrieNode* children[SIZE];
    bool isTerminal = false;
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();        
    }
    
    void insert(string word) {
        struct TrieNode* temp = root;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(!temp->children[index])
                temp->children[index] = new TrieNode();
            temp = temp->children[index];    
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        struct TrieNode* temp = root;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(!temp->children[index])
                return false;
            temp = temp->children[index];    
        }
        return temp->isTerminal;   
    }
    
    bool startsWith(string prefix) {
        struct TrieNode* temp = root;
        for(int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if(!temp->children[index])
                return false;
            temp = temp->children[index];    
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