// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    // 76 ms
    // 25.9 MB
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result(A.size());
        
        int start = 0;
        int end = A.size() - 1;
        int index = end;
        while (start <= end) {
            if (abs(A[start]) < abs(A[end])) {
                result[index] = A[end] * A[end];
                --end;
            } else {
                result[index] = A[start] * A[start];
                ++start;
            }
            --index;
        }
        return result;
    }
};