// https://leetcode.com/problems/powx-n/

class Solution {
public:
    // 0 ms
    // 5.9 MB
    double myPow(double x, int n) {
        double result = 1.0;
        double step;
        long long exp;
        if (n < 0) {
            step = 1.0 / x;
            exp = ~n + 1LL;
        } else {
            step = x;
            exp = n;
        }
        
        for (int i = 0; exp && i < 32; ++i) {
            if (exp & (1 << i)) {
                result *= step;
                exp -= (1 << i);
            }
            step *= step;
        }
        return result;
    }
};