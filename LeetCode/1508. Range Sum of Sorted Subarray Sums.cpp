// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

class Solution {
public:
    // 812 ms...
    // 19.5 MB
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> accumulateSum(nums.size(), 0);
        vector<int> sums;
        accumulateSum[0] = nums[0];
        sums.push_back(accumulateSum[0]);
        for (int i = 1; i < nums.size(); ++i) {
            accumulateSum[i] = accumulateSum[i - 1] + nums[i];
            sums.push_back(accumulateSum[i]);
        }
        
        for (int i = 0; i < accumulateSum.size(); ++i) {
            for (int j = i + 1; j < accumulateSum.size(); ++j) {
                sums.push_back(accumulateSum[j] - accumulateSum[i]);
            }
        }
        
        std::sort(sums.begin(), sums.end());
        int result = sums[left - 1];
        int mod = 1e9 + 7;
        while (left < right) {
            result = (result + sums[left]) % mod;
            ++left;
        }
        return result;
    }
};