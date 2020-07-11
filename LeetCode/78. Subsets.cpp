// https://leetcode.com/problems/subsets/

class Solution {
    vector<int> origin;
public:
    // 0 ms
    // 7.3 MB
    vector<vector<int>> subsets(vector<int>& nums) {
        origin = nums;
        vector<vector<int>> result;
        vector<int> currSet;
        search(0, currSet, result);
        return result;
    }
    
    void search(int index, vector<int>& currSet, vector<vector<int>>& result) {
        if (index == origin.size()) {
            result.push_back(currSet);
            return;
        }
        
        currSet.push_back(origin[index]);
        search(index + 1, currSet, result);
        currSet.pop_back();
        search(index + 1, currSet, result);
        return;
    }
};