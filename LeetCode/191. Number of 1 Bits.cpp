// https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    // 0 ms
    // 6 MB
    int hammingWeight(uint32_t n) {
        return bitCount(n);
    }
    
    int bitCount(unsigned int x) {
        x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
        x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
        x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
        return x;
    }
};