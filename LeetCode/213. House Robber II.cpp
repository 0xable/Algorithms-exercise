// https://leetcode.com/problems/house-robber-ii/
// 4 ms
// 8.3 MB

class Solution {
    vector<vector<int>> cache;
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return std::max(nums[0], nums[1]);
        cache.assign(nums.size(), vector<int>(2, 0));
        int result;
        int n = nums.size() - 1;
        cache[0][0] = 0;
        cache[0][1] = nums[0];
        for (int i = 1; i < n; ++i) {
            cache[i][0] = std::max(cache[i - 1][0], cache[i - 1][1]);
            cache[i][1] = cache[i - 1][0] + nums[i];
        }
        result = std::max(cache[n - 1][0], cache[n - 1][1]);
        
        cache[1][0] = 0;
        cache[1][1] = nums[1];
        for (int i = 2; i < nums.size(); ++i) {
            cache[i][0] = std::max(cache[i - 1][0], cache[i - 1][1]);
            cache[i][1] = cache[i - 1][0] + nums[i];
        }
        result = std::max(result, std::max(cache[n][0], cache[n][1]));
        return result;
    }
};