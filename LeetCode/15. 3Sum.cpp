// https://leetcode.com/problems/3sum/

class Solution {
public:
    // 384 ms
    // 27 MB
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        set<vector<int>> check;
        vector<vector<int>> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                int currSum = nums[i] + nums[j] + nums[k];
                
                if (currSum == 0) {
                    if (!check.count({nums[i], nums[j], nums[k]})) {
                        check.insert({nums[i], nums[j], nums[k]});
                        result.push_back({nums[i], nums[j], nums[k]});
                    }
                    while (j < k && nums[j] == nums[j + 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k - 1]) {
                        --k;
                    }
                    ++j;
                    --k;
                } else if (currSum > 0) {
                    while (j < k && nums[k] == nums[k - 1]) {
                        --k;
                    }
                    --k;
                } else {
                    while (j < k && nums[j] == nums[j + 1]) {
                        ++j;
                    }
                    ++j;
                }
            }
        }
        return result;
    }
};