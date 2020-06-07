// https://algospot.com/judge/problem/read/NUMBERGAME
// 구종만, 알고리즘 문제 해결 전략, 인사이트, 2012, 340 - 344 참조
// 4 ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int n;
    vector<int> numbers;
    vector<vector<int>> cache;

public:
    Solution(int n, vector<int>& numbers) : n{n}, numbers{numbers}, cache(n, vector<int>(n, -987654321)) {

    }

    int search() {
        return search(0, n - 1);
    }

    int search(int left, int right) {
        if (left > right) return 0;
        if (cache[left][right] != -987654321) return cache[left][right];

        int result = std::max(numbers[left] - search(left + 1, right), numbers[right] - search(left, right - 1));
        if (right - left + 1 >= 2) {
            result = std::max(result, -search(left + 2, right));
            result = std::max(result, -search(left, right - 2));
        }
        return cache[left][right] = result;
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
        vector<int> numbers(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }
        
        Solution s(n, numbers);
        cout << s.search() << endl;
    }
    return 0;
}