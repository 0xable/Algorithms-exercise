// https://leetcode.com/problems/shuffle-string/

class Solution {
public:
    // 16 ms
    // 15.5 MB
    string restoreString(string s, vector<int>& indices) {
        vector<char> result(s.length());
        for (int i = 0; i < s.length(); ++i) {
            result[indices[i]] = s[i];
        }
        return string(result.begin(), result.end());
    }
};