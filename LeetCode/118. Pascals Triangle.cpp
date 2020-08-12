// https://leetcode.com/problems/pascals-triangle/
// 0 ms
// 6.5 MB

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        vector<int> prev;
        for (int i = 0; i < numRows; ++i) {
            vector<int> curr;
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    curr.push_back(1);
                } else {
                    curr.push_back(prev[j] + prev[j - 1]);
                }
            }
            result[i] = curr;
            prev = std::move(curr);
        }
        return result;
    }
};