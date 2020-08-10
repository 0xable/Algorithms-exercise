// https://leetcode.com/problems/find-pivot-index/
// 40 ms
// 31.6 MB

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        
        vector<int> accumulateSum(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            accumulateSum[i] = accumulateSum[i - 1] + nums[i - 1];
        }
        
        int lastIndex = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (accumulateSum[i] == (accumulateSum[lastIndex] - accumulateSum[i + 1]))
                return i;
        }
        return -1;
    }
};