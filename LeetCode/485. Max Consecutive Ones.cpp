// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    // 156 ms
    // 36.4 MB
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current = 0;
        int result = 0;
        for (auto i : nums) {
            if (i) {
                ++current;
            } else {
                result = std::max(result, current);
                current = 0;
            }
        }
        return std::max(result, current);
    }
};