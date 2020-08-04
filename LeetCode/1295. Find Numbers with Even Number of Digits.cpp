// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
public:
    // 16 ms
    // 9.8 MB
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (auto x : nums) {
            int digits = 0;
            while (x) {
                ++digits;
                x /= 10;
            }
            if (digits % 2 == 0) ++result;
        }
        return result;
    }
};