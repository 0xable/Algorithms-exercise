// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    // 12 ms
    // 7.2 MB
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                ++l;
            }
            while (l < r && !isalnum(s[r])) {
                --r;
            }
            if (tolower(s[l]) != tolower(s[r])) return false;
            ++l;
            --r;
        }
        return true;
    }
};