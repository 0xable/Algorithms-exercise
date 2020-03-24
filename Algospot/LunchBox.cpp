// https://algospot.com/judge/problem/read/LUNCHBOX

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> microwave(n);
        vector<pair<int, int>> schedule(n);
        for (int i = 0; i < n; ++i) {
            cin >> microwave[i];
        }
        int temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            schedule[i] = make_pair(microwave[i], temp);
        }

        std::sort(schedule.begin(), schedule.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second > b.second) {
                return true;
            } else {
                return false;
            }
        });
        
        int answer = 0;
        int cookingTime = 0;
        for (int i = 0; i < n; ++i) {
            cookingTime += schedule[i].first;
            answer = std::max(answer, cookingTime + schedule[i].second);
        }
        cout << answer << endl;
    }
    return 0;
}