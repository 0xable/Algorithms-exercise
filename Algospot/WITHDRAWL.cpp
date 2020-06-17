// https://algospot.com/judge/problem/read/WITHDRAWAL
// 구종만, 알고리즘 문제 해결 전략, 인사이트, 2012, p458 - 462 참조
// 72 ms

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Solution {
    int n, k;
    vector<int> rank;
    vector<int> total;

public:
    Solution(int n, int k, vector<int>& rank, vector<int>& total) : n{n}, k{k}, rank{rank}, total{total} {

    }

    double search() {
        double grade = 1.0;
        double step = 0.5;
        while (step > 0.0000000001) {
            while (grade - step > 0 && isPossible(grade - step)) {
                grade -= step;
            }
            step /= 2;
        }
        return grade;
    }

    bool isPossible(double grade) {
        double result = 0;
        vector<double> eachRank(n);
        for (int i = 0; i < n; ++i) {
            eachRank[i] = (grade * total[i]) - rank[i];
        }
        std::sort(eachRank.begin(), eachRank.end(), greater<double>());
        for (int i = 0; i < k; ++i) {
            result += eachRank[i];
        }
        return result >= 0.0;
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
        vector<int> rank(n);
        vector<int> total(n);
        for (int i = 0; i < n; ++i) {
            cin >> rank[i];
            cin >> total[i];
        }

        Solution s(n, k, rank, total);
        cout << setprecision(10) << std::fixed;
        cout << s.search() << endl;
    }
    return 0;
}