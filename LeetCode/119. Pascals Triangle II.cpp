// https://leetcode.com/problems/pascals-triangle-ii/
// 0 ms
// 6.3 MB

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == i || j == 0) {
                    result[j] = 1;
                } else {
                    result[j] = result[j] + result[j - 1];
                }
            }
        }
        return result;
    }
};