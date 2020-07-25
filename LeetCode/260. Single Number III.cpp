// https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    // 20 ms
    // 10 MB
    vector<int> singleNumber(vector<int>& nums) {
        int xorResult = std::accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int diff = xorResult & -xorResult;
        
        int num1 = 0;
        int num2 = 0;
        for (auto x : nums) {
            if (x & diff) {
                num1 ^= x;
            } else {
                num2 ^= x;
            }
        }
        return { num1, num2 };
    }
    
    // 32 ms
    // 10.1 MB
    vector<int> singleNumber_(vector<int>& nums) {
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