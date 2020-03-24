// https://algospot.com/judge/problem/read/MATCHORDER

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
        vector<int> russia(n);
        vector<int> korea(n);
        for (int i = 0; i < n; ++i) cin >> russia[i];
        for (int i = 0; i < n; ++i) cin >> korea[i];

        std::sort(russia.begin(), russia.end());
        std::sort(korea.begin(), korea.end());
        int i = 0;
        int j = 0;
        int winCount = 0;
        while (i < n) {
            if (korea[i] < russia[j]) {
                ++i;
            } else {
                ++winCount;
                ++i;
                ++j;
            }
        }
        cout << winCount << endl;
    }
    return 0;
}