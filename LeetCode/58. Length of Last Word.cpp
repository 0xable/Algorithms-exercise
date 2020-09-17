// https://leetcode.com/problems/length-of-last-word/
// 4 ms
// 6.5 MB

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = 0;
        while (i < s.length()) {
            count = 0;
            while (i < s.length() && s[i] != ' ') {
                ++i;
                ++count;
            }
            while (i < s.length() && s[i] == ' ') {
                ++i;
            }
        }
        return count;
    }
};