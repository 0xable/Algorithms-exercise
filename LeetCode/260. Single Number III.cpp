// https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    // 32 ms
    // 10.1 MB
    vector<int> singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<int> result;
        
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] != nums[i - 1]) {
                result.push_back(nums[i - 1]);
                i += 1;
            } else {
                i += 2;
            }
        }
        
        if (result.size() == 1)
            result.push_back(nums.back());
        return result;
    }
};