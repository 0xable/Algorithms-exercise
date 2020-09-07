// https://leetcode.com/problems/contains-duplicate-iii/
// 44 ms
// 15.4 MB

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<long long, long long> table;
        long long range = (long long) t + 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (k < i) {
                if (nums[i - k - 1] < 0) {
                    table.erase((nums[i - k - 1] / range) - 1);
                } else {
                    table.erase(nums[i - k - 1] / range);
                }
            }
            long long curr = nums[i];
            long long bucket = curr < 0 ? (curr / range) - 1 : curr / range;
            if (table.count(bucket)) return true;
            if (table.count(bucket - 1) && abs(table[bucket - 1] - curr) < range) return true;
            if (table.count(bucket + 1) && abs(table[bucket + 1] - curr) < range) return true;
            table[bucket] = curr;
        }
        return false;
    }
};