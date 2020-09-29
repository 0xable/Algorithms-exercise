// https://leetcode.com/problems/word-break/
// 0 ms
// 7.9 MB

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> check(s.length() + 1, false);
        search(0, s, wordDict, check);
        return check[s.length()];
    }
    
    void search(int index, string& s, vector<string>& wordDict, vector<bool>& check) {
        if (index == s.length()) {
            check[index] = true;
            return;
        }
        if (check[index]) return;
        
        for (string& curr : wordDict) {
            if (index + curr.length() > s.length()) continue;
            for (int i = 0; i < curr.length(); ++i) {
                if (curr[i] != s[index + i]) break;
                if (i == curr.length() - 1) search(index + curr.length(), s, wordDict, check);
            }
        }
        check[index] = true;
        return;
    }
};