// https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    // 4 ms
    // 5.9 MB
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = n;
        result = ((result & 0xffff0000) >> 16) + ((result & 0x0000ffff) << 16);
        result = ((result & 0xff00ff00) >> 8) + ((result & 0x00ff00ff) << 8);
        result = ((result & 0xf0f0f0f0) >> 4) + ((result & 0x0f0f0f0f) << 4);
        result = ((result & 0xcccccccc) >> 2) + ((result & 0x33333333) << 2);
        result = ((result & 0xaaaaaaaa) >> 1) + ((result & 0x55555555) << 1);
        return result;
    }
};