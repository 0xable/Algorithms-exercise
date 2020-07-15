// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    // 20 ms
    // 9.2 MB
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }

        auto iter = words.rbegin();
        if (iter == words.rend()) return "";
        
        string result = "";
        while (iter != words.rend()) {
            result += *iter + " ";
            ++iter;
        }
        result.pop_back();
        return result;
    }
};