// https://cses.fi/problemset/task/1097

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr long long INF = 54321987654321;

class Solution {
    int n;
    long long totalSum;
    vector<int> numbers;
    vector<vector<long long>> cache;
public:
    Solution(int n, vector<int>& num) : n{n}, numbers{num}, cache(n, vector<long long>(n, INF)) {
        totalSum = 0;
        for (auto x : numbers) {
            totalSum += x;
        }
    }

    long long search() {
        long long result = totalSum + search(0, n - 1);
        result /= 2;
        return result;
    }

    long long search(int left, int right) {
        if (left + 1 == right) {
            return cache[left][right] = std::max(numbers[left], numbers[right]) - std::min(numbers[left], numbers[right]);
        }
        if (cache[left][right] != INF) return cache[left][right];

        long long l = numbers[left] - search(left + 1, right);
        long long r = numbers[right] - search(left, right - 1);
        return cache[left][right] = std::max(l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    Solution s(n, numbers);
    cout << s.search() << endl;
    return 0;
}