// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    // 124 ms
    // 33.6 MB
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) result.push_back(index + 1);
            nums[index] = -nums[index];
        }
        return result;
    }
};