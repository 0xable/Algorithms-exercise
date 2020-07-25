// https://leetcode.com/problems/missing-number/

class Solution {
public:
    // 56 ms
    // 18.1 MB
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            result ^= nums[i] ^ i;
        }
        return result;
    }
    
    // 52 ms
    // 18.1 MB
    int missingNumber_(vector<int>& nums) {
        long long size = nums.size();
        long long sum = size * (size + 1) / 2;
        for (auto x : nums) {
            sum -= x;
        }
        return sum;
    }
};