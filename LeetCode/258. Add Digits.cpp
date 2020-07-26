// https://leetcode.com/problems/add-digits/

class Solution {
public:
    // 4 ms
    // 5.9 MB
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};