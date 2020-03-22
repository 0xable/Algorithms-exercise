// https://algospot.com/judge/problem/read/CLOCKSYNC

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int n, l;
    while (t--) {
        cin >> n >> l;
        vector<int> cost(n);
        for (int i = 0; i < n; ++i) {
            cin >> cost[i];
        }
        double minAvr = 987654321;
        auto rangeStart = cost.begin();
        auto rangeEnd = cost.begin() + l;
        for (int i = 0; i <= n - l; ++i) {
            double dayCostSum = accumulate(rangeStart, rangeEnd, 0.0);
            double avrCost = dayCostSum / l;
            if (avrCost < minAvr) minAvr = avrCost;
            for (int j = i + l; j < n; ++j) {
                dayCostSum += cost[j];
                double avrCost = dayCostSum / (j - i + 1);

                if (avrCost < minAvr) {
                    minAvr = avrCost;
                }
            }
            rangeStart++;
            rangeEnd++;
        }
        cout << std::fixed << std::setprecision(12);
        cout << minAvr << endl;
    }
    return 0;
}