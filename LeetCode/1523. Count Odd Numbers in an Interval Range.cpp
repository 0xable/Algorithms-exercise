https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

class Solution {
public:
    // 0 ms
    // 5.9 MB
    int countOdds(int low, int high) {
        if (low % 2 == 0 && high % 2 == 0) {
            return (high - low) / 2;
        }
        return (high - low) / 2 + 1;
    }
};