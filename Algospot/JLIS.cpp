// https://algospot.com/judge/problem/read/JLIS

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
    int n, m;
    vector<int> a, b;
    vector<vector<long long>> cache;
    long long NEGINF;
public:
    Solution(int n, int m, vector<int> aa, vector<int> bb) : n{n}, m{m}, a{aa}, b{bb} {
        int maxSize = std::max(n, m);
        NEGINF = numeric_limits<long long>::min();
        cache.assign(maxSize + 1, vector<long long>(maxSize + 1, NEGINF));
    }

    long long search(int indexA, int indexB) {
        long long result = cache[indexA + 1][indexB + 1];
        if (result != NEGINF) return result;
        
        long long aVal = (indexA == -1 ? NEGINF : a[indexA]);
        long long bVal = (indexB == -1 ? NEGINF : b[indexB]);
        result = 0;

        long long maxElement = std::max(aVal, bVal);
        for (int nextA = indexA + 1; nextA < n; ++nextA) {
            if (maxElement < a[nextA]) {
                result = std::max(result, search(nextA, indexB) + 1);
            }
        }
        for (int nextB = indexB + 1; nextB < m; ++nextB) {
            if (maxElement < b[nextB]) {
                result = std::max(result, search(indexA, nextB) + 1);
            }
        }
        return cache[indexA + 1][indexB + 1] = result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        Solution s(n, m, a, b);
        cout << s.search(-1, -1) << endl;
    }
    return 0;
}