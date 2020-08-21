// https://leetcode.com/problems/sort-array-by-parity/
// 16 ms
// 16.5 MB

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int odd = 0;
        int even = 0;
        
        while (odd < A.size() && even < A.size()) {
            while (odd < A.size() && A[odd] % 2 == 0) {
                ++odd;
            }
            while (even < A.size() && A[even] % 2 == 1) {
                ++even;
            }
            
            if (odd == A.size() || even == A.size()) break;
            if (odd < even) {
                std::swap(A[odd], A[even]);
            } else {
                ++even;
            }
        }
        return A;
    }
};