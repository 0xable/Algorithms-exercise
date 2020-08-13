// https://leetcode.com/problems/permutations/
// 4 ms
// 7.9 MB

class Solution {
    vector<int> base;
    vector<bool> used;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        base = nums;
        used.assign(nums.size(), false);
        vector<vector<int>> result;
        vector<int> curr;
        search(0, curr, result);
        return result;
    }
    
    void search(int currNum, vector<int>& curr, vector<vector<int>>& result) {
        if (currNum == base.size()) {
            result.push_back(curr);
            return;
        }
        
        for (int i = 1; i <= base.size(); ++i) {
            if (used[i - 1]) continue;
            
            curr.push_back(base[i - 1]);
            used[i - 1] = true;
            search(currNum + 1, curr, result);
            curr.pop_back();
            used[i - 1] = false;
        }
    }
};