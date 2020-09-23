// https://leetcode.com/problems/gas-station/
// 12 ms
// 9.8 MB

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0, k;
        long long curr = 0;
        while (i < gas.size()) {
            k = -1;
            curr = 0;
            while (curr >= 0 && k < n) {
                ++k;
                curr += gas[(i + k) % n] - cost[(i + k) % n];
            }
            if (k == n) return i;
            i += k + 1;
        }
        return -1;
    }
};