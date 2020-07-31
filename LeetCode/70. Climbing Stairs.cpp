// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    // 0 ms
    // 6.3 MB
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> table(n + 1, 0);
        table[1] = 1;
        table[2] = 2;
        for (int i = 3; i <= n; ++i) {
            table[i] = table[i - 1] + table[i - 2];
        }
        return table[n];
    }
};