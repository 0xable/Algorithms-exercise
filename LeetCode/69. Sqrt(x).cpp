// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    // 0 ms
    // 6.2 MB
    int mySqrt(int x) {
        int result = 0;
        int step = 1 << 15;
        while (step) {
            while (square(result + step) <= x) {
                result += step;
            }
            step /= 2;
        }
        return result;
    }
                
    long long square(long long x) {
        return x * x;
    }
};