// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    // 44 ms
    // 13.8 MB
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        for (auto k : nums) {
            if (table.count(k)) {
                table[k]++;
            } else {
                table[k] = 1;
            }
        }
        
        vector<pair<int, int>> temp;
        for (auto& p : table) {
            temp.push_back(make_pair(p.second, p.first));
        }
        std::sort(temp.begin(), temp.end(), std::greater<pair<int, int>>());
        
        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = temp[i].second;
        }
        return result;
    }
};