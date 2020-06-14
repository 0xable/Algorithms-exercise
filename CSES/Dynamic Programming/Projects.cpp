// https://cses.fi/problemset/task/1140

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<tuple<int, int, long long>> schedule(n);

    int a, b;
    long long p;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> p;
        schedule[i] = make_tuple(a, b, p);
    }
    std::sort(schedule.begin(), schedule.end(), [](tuple<int, int, long long>& a, tuple<int, int, long long>& b) {
        return get<1>(a) < get<1>(b);
    });

    vector<pair<int, long long>> table;
    table.push_back(make_pair(0, 0));
    table.push_back(make_pair(get<1>(schedule[0]), get<2>(schedule[0])));

    int currStart, currEnd;
    long long currReward;
    for (int i = 1; i < schedule.size(); ++i) {
        tie(currStart, currEnd, currReward) = schedule[i];

        int prevIndex = 0;
        int step = table.size();
        while (step) {
            while (prevIndex + step < table.size() && table[prevIndex + step].first < currStart) {
                prevIndex += step;
            }
            step /= 2;
        }

        int last = table.size() - 1;
        if (table[last].first != currEnd) {
            long long currMax = table[last].second;
            table.push_back(make_pair(currEnd, std::max(currMax, table[prevIndex].second + currReward)));
        } else {
            table[last].second = std::max(table[last].second, table[prevIndex].second + currReward);
        }
    }

    long long result = -1;
    for (auto p : table) {
        result = std::max(result, p.second);
    }
    cout << result << endl;
    return 0;
}