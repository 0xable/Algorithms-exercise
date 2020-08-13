// https://leetcode.com/problems/combinations/
// 36 ms
// 9.2 MB

class Solution {
    int n;
    int k;
public:
    vector<vector<int>> combine(int n, int k) {
        this -> n = n;
        this -> k = k;
        vector<vector<int>> result;
        vector<int> current;
        search(1, current, result);
        return result;
    }
    
    void search(int next, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        
        for (int i = next; i <= n; ++i) {
            current.push_back(i);
            search(i + 1, current, result);
            current.pop_back();
        }
        return;
    }
};