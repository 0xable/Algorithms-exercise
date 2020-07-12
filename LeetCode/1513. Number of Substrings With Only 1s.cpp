// https://leetcode.com/problems/number-of-substrings-with-only-1s/

class Solution {
public:
    // 72 ms
    // 8.9 MB
    int numSub(string s) {
        int result = 0;
        long long oneCount = 0;
        int mod = 1e9 + 7;
        
        for (auto ch : s) {
            if (ch == '1') {
                ++oneCount;
            } else {
                long long curr = (oneCount * (oneCount + 1) / 2) % mod;
                result = (result + curr) % mod;
                oneCount = 0;
            }
        }
        
        long long curr = (oneCount * (oneCount + 1) / 2) % mod;
        result = (result + curr) % mod;
        return result;
    }
};