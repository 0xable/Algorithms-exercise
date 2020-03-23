// https://algospot.com/judge/problem/read/LIS

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
        
        vector<int> seq(n);
        vector<int> count(n, 1);
        for (int i = 0; i < n; ++i) {
            cin >> seq[i];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (seq[j] < seq[i]) {
                    count[i] = std::max(count[i], count[j] + 1);
                }
            }
        }
        cout << *max_element(count.begin(), count.end()) << endl;
    }
    return 0;
}