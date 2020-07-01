// https://algospot.com/judge/problem/read/POTION
// 4 ms

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    int n;
    vector<int> ratio;
    vector<int> curr;

public:
    Solution(int n, vector<int>& ratio, vector<int>& curr) : n{n}, ratio{ratio}, curr{curr} {
        
    }

    int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        int temp = a / gcd(a, b);
        return temp * b;
    }

    int totalGcd() {
        int result = ratio[0];
        for (int i = 1; i < n; ++i) {
            result = gcd(result, ratio[i]);
        }
        return result;
    }

    vector<int> search() {
        int d = totalGcd();
        for (int i = 0; i < n; ++i) {
            ratio[i] /= d;
        }

        int maxRatio = -1;
        for (int i = 0; i < n; ++i) {
            int temp = ceil((double) curr[i] / ratio[i]);
            maxRatio = std::max(maxRatio, temp);
        }

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            ratio[i] *= maxRatio;
            result[i] = ratio[i] - curr[i];
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> ratio(n);
        vector<int> curr(n);

        for (int i = 0; i < n; ++i) {
            cin >> ratio[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> curr[i];
        }
        
        Solution s(n, ratio, curr);
        auto result = s.search();
        for (auto x : result) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}