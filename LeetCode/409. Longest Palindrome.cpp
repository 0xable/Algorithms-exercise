// https://leetcode.com/problems/longest-palindrome/
// 4 ms
// 6.7 MB

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lowerCase(26, 0);
        vector<int> upperCase(26, 0);
        for (auto ch : s) {
            if (ch & 0x20) {
                lowerCase[ch - 'a']++;
            } else {
                upperCase[ch - 'A']++;
            }
        }
        
        int odd = 0;
        int result = 0;
        for (auto i : lowerCase) {
            if (i % 2 == 0) {
                result += i;
            } else {
                result += (i - 1);
                odd = 1;
            }
        }
        for (auto i : upperCase) {
            if (i % 2 == 0) {
                result += i;
            } else {
                result += (i - 1);
                odd = 1;
            }
        }
        return result + odd;
    }
};