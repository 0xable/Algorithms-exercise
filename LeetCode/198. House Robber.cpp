// https://leetcode.com/problems/house-robber/
// 0 ms
// 8.1 MB

class Solution {
    vector<int> cache;
public:
    int rob(vector<int>& nums) {
        cache.assign(nums.size(), -1);
        return search(nums, nums.size() - 1);
    }
    
    int search(vector<int>& nums, int index) {
        if (index < 0) return 0;
        if (index == 0) return nums[0];
        if (index == 1) return std::max(nums[0], nums[1]);
        if (cache[index] != -1) return cache[index];
        
        return cache[index] = std::max(search(nums, index - 2) + nums[index], search(nums, index - 1));
    }
};