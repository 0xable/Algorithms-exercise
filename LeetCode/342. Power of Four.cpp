// https://leetcode.com/problems/power-of-four/

class Solution {
public:
    // 0 ms
    // 5.9 MB
    bool isPowerOfFour(int num) {
        if (num == 0) return false;
        if ((num & 0x55555555) != num) return false;
        if ((num & (num - 1)) == 0) return true;
        return false;
    }
};