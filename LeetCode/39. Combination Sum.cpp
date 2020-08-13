// https://leetcode.com/problems/combination-sum/
// 12 ms
// 10.8 MB

class Solution {
    int target;
    vector<int> candidates;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this -> target = target;
        this -> candidates = candidates;
        vector<vector<int>> result;
        vector<int> curr;
        search(0, 0, curr, result);
        return result;
    }
    
    void search(int next, int currSum, vector<int>& curr, vector<vector<int>>& result) {
        if (next == candidates.size()) return;
        if (currSum > target) {
            return;
        } else if (currSum == target) {
            result.push_back(curr);
            return;
        }
        
        curr.push_back(candidates[next]);
        search(next, currSum + candidates[next], curr, result);
        curr.pop_back();
        search(next + 1, currSum, curr, result);
    }
};