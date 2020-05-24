// https://algospot.com/judge/problem/read/QUANTIZE
// 구종만, 알고리즘 문제 해결 전략, 인사이트, 2012, p244 - 251 참조

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int n, s;
    vector<int> num;
    vector<int> pSum, pSqSum;
    vector<vector<int>> cache;
public:
    Solution(int n, int s, vector<int>& num) : n{n}, s{s}, num{num}, cache(n, vector<int>(s + 1, -1)), pSum(n, 0), pSqSum(n, 0) {
        std::sort(num.begin(), num.end());
        pSum[0] = num[0];
        pSqSum[0] = num[0] * num[0];
        for (int i = 1; i < n; ++i) {
            pSum[i] = pSum[i - 1] + num[i];
            pSqSum[i] = pSqSum[i - 1] + num[i] * num[i];
        }
    }

    int minError(int lo, int hi) {
        int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
        int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);

        int m = int(0.5 + (double) sum / (hi - lo + 1));
        int result = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
        return result;
    }

    int grouping(int start, int group) {
        if (group == 1) return minError(start, n - 1);
        if (start == n - 1) return 0;
        if (cache[start][group] != -1) return cache[start][group];
        
        int result = 987654321;
        for (int partSize = 1; start + partSize < n; ++partSize) {
            result = std::min(result, minError(start, start + partSize - 1) + grouping(start + partSize, group - 1));
        }
        return cache[start][group] = result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> num(n);
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        
        Solution s(n, k, num);
        cout << s.grouping(0, k) << endl;
    }
    return 0;
}