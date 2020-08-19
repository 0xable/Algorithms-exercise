// https://leetcode.com/problems/numbers-with-same-consecutive-differences/
// 0 ms
// 7.9 MB

class Solution {
    int n;
    int k;
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        this -> n = N;
        this -> k = K;
        
        vector<int> result;
        if (n == 1) result.push_back(0);
        for (int i = 1; i <= 9; ++i) {
            search(1, i, result);
        }
        return result;
    }
    
    void search(int i, int curr, vector<int>& result) {
        if (i == n) {
            result.push_back(curr);
            return;
        }
        
        int currDigit = curr % 10;
        curr *= 10;
        if (k == 0) {
            search(i + 1, curr + currDigit, result);
            return;
        }
        if (currDigit - k >= 0) search(i + 1, curr + (currDigit - k), result);
        if (currDigit + k <= 9) search(i + 1, curr + (currDigit + k), result);
    }
};