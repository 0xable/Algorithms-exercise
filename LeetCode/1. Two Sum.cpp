// https://leetcode.com/problems/two-sum/

class Solution {
public:
    // 40 ms
    // 10.2 MB
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> table;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (table.count(target - nums[i])) {
                result.push_back(table[target - nums[i]]);
                result.push_back(i);
                break;
            }
            table[nums[i]] = i;
        }
        return result;
    }
};