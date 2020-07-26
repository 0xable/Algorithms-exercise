// https://leetcode.com/problems/bulb-switcher-iv/

class Solution {
public:
    // 48 ms
    // 9.6 MB
    int minFlips(string target) {
        int count = 0;
        int prev = target[0] - '0';
        if (prev) ++count;
        
        for (int i = 1; i < target.length(); ++i) {
            if (target[i] != target[i - 1]) ++count;
        }
        return count;
    }
};