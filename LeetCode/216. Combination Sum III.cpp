// https://leetcode.com/problems/combination-sum-iii/
// 0 ms
// 6.5 MB

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> result;
        search(1, k, n, curr, result);
        return result;
    }
    
    void search(int index, int k, int remain, vector<int>& curr, vector<vector<int>>& result) {
        if (k == 0) {
            if (remain == 0) result.push_back(curr);
            return;
        }
        
        for (int i = index; i <= 9; ++i) {
            curr.push_back(i);
            search(i + 1, k - 1, remain - i, curr, result);
            curr.pop_back();
        }
        return;
    }
};