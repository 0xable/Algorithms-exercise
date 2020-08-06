// https://leetcode.com/problems/add-and-search-word-data-structure-design/

// 200 ms
// 45 MB
class WordDictionary {
public:
    class Trie {
    public:
        bool terminal;
        vector<Trie*> next;
        Trie() {
            terminal = false;
            next.assign(26, nullptr);
        }
    };
    
    Trie* root;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie* curr = root;
        int nextIndex;
        
        for (auto ch : word) {
            nextIndex = ch - 'a';
            if (curr -> next[nextIndex] == nullptr) curr -> next[nextIndex] = new Trie();
            curr = curr -> next[nextIndex];
        }
        curr -> terminal = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(root, word, 0);
    }
    
    bool search(Trie* curr, string& word, int index) {
        if (index == word.length()) return curr -> terminal;
        
        if (word[index] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (curr -> next[i] != nullptr && search(curr -> next[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        }
        
        int nextIndex = word[index] - 'a';
        if (curr -> next[nextIndex] == nullptr) return false;
        return search(curr -> next[nextIndex], word, index + 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */