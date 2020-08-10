// https://leetcode.com/problems/subarray-sum-equals-k/
// 72 ms
// 22.2 MB

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        table[0] = 1;
        
        int result = 0;
        int currSum = 0;
        for (auto x : nums) {
            currSum += x;
            if (table.count(currSum - k)) {
                result += table[currSum - k];
            }
            
            if (table.count(currSum)) {
                table[currSum] += 1;
            } else {
                table[currSum] = 1;
            }
        }
        return result;
    }
};
