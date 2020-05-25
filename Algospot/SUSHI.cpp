// https://algospot.com/judge/problem/read/SUSHI

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
        int n, m;
        cin >> n >> m;
        m /= 100;
        vector<int> price(n);
        vector<int> prefer(n);
        vector<int> table(m + 1, 0);

        for (int i = 0; i < n; ++i) {
            cin >> price[i];
            price[i] /= 100;
            cin >> prefer[i];
        }

        for (int i = 1; i <= m; ++i) {
            for (int k = 0; k < n; ++k) {
                if (i >= price[k]) {
                    table[i] = std::max(table[i], table[i - price[k]] + prefer[k]);
                }
            }
        }
        cout << table[m] << endl;
    }
    return 0;
}