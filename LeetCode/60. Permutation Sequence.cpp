// https://leetcode.com/problems/permutation-sequence/
// 0 ms
// 6.1 MB

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<bool> used(n + 1, false);
        vector<int> p(n + 1, 0);
        p[0] = 1;
        p[1] = 1;
        for (int i = 2; i <= n; ++i) {
            p[i] = p[i - 1] * i;
        }
        
        vector<char> result(n);
        for (int i = 1; i <= n; ++i) {
            int nextIth = 1;
            while (k > p[n - i]) {
                k -= p[n - i];
                ++nextIth;
            }
            int next = 1;
            for (; next <= 9 && nextIth > 0; ++next) {
                if (used[next]) continue;
                --nextIth;
            }
            --next;
            used[next] = true; 
            result[i - 1] = '0' + next;
        }
        return string(result.begin(), result.end());
    }
};