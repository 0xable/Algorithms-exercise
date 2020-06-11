// https://cses.fi/problemset/task/1744

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int a, b;
    vector<vector<int>> cache;

public:
    Solution(int a, int b) : a{a}, b{b}, cache(a + 1, vector<int>(b + 1, 987654321)) {

    }

    int search() {
        return search(a, b);
    }

    int search(int w, int h) {
        if (w == h) return 0;
        if (cache[w][h] != 987654321) return cache[w][h];

        int result = 987654321;
        for (int len = 1; len < w; ++len) {
            result = std::min(result, search(len, h) + search(w - len, h) + 1);
        }
        for (int len = 1; len < h; ++len) {
            result = std::min(result, search(w, len) + search(w, h - len) + 1);
        }
        return cache[w][h] = result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    Solution s(a, b);
    cout << s.search() << endl;
    return 0;
}