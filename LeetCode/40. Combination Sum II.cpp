// https://leetcode.com/problems/combination-sum-ii/
// 12 ms
// 10.6 MB

class Solution {
    int target;
    vector<int> candidates;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this -> target = target;
        this -> candidates = candidates;
        std::sort(this -> candidates.begin(), this -> candidates.end());
        
        vector<int> curr;
        vector<vector<int>> result;
        search(0, 0, curr, result);
        return result;
    }
    
    void search(int start, int currSum, vector<int>& curr, vector<vector<int>>& result) {
        if (currSum > target) return;
        if (currSum == target) {
            result.push_back(curr);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            curr.push_back(candidates[i]);
            search(i + 1, currSum + candidates[i], curr, result);
            curr.pop_back();
        }
    }
};