// https://leetcode.com/problems/total-hamming-distance/

class Solution {
public:
    // 160 ms
    // 19.1 MB
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        int length = nums.size();
        vector<int> eachBitCount(32, 0);
        
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < 32; ++j) {
                eachBitCount[j] += (nums[i] & (1 << j)) ? 1 : 0;
            }
        }
        
        for (auto x : eachBitCount) {
            result += x * (length - x);
        }
        return result;
    }
};