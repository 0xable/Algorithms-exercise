// https://leetcode.com/problems/excel-sheet-column-number/
// 0 ms
// 6 MB

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (auto ch : s) {
            result *= 26;
            result += (ch - 'A' + 1);
        }
        return result;
    }
};