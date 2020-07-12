// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

class Solution {
public:
    // 372 ms
    // 35.4 MB
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 3) return 0;
        
        std::sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 4;
        int minDiff = numeric_limits<int>::max();
        
        for (int i = 0; i <= 3; ++i) {
            minDiff = std::min(minDiff, nums[r + i] - nums[l + i]);
        }
        return minDiff;
    }
};