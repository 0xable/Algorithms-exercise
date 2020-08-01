// https://leetcode.com/problems/detect-capital/

class Solution {
public:
    // 4 ms
    // 6.1 MB
    bool detectCapitalUse(string word) {
        if (word[0] & 0x20) {
            // lower case
            for (int i = 1; i < word.size(); ++i) {
                if (!(word[i] & 0x20)) return false;
            }
        } else {
            // upper case
            for (int i = 2; i < word.size(); ++i) {
                if ((word[i] ^ word[i - 1]) & 0x20) return false;
            }
        }
        return true;
    }
};