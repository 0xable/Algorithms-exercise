// https://leetcode.com/problems/word-pattern/
// 0 ms
// 6.6 MB

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> table;
        map<string, char> inverseTable;
        stringstream ss(str);
        
        string word;
        for (auto letter : pattern) {
            if (!getline(ss, word, ' ')) return false;
            if (table.count(letter)) {
                if (table[letter] != word) return false;
            } else {
                if (inverseTable.count(word)) return false;
                table[letter] = word;
                inverseTable[word] = letter;
            }
        }
        if (getline(ss, word, ' ')) return false;
        return true;
    }
};