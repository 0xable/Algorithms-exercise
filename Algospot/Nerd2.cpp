// https://algospot.com/judge/problem/read/NERD2

#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, p, q;
        cin >> n;

        map<int, int> table;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            cin >> p >> q;
            auto lb = table.lower_bound(p);
            if (lb == table.end()) {
                table[p] = q;
            } else {
                if (lb -> second < q) {
                    table[p] = q;
                } else {
                    result += table.size();
                    continue;
                }
            }

            lb = table.lower_bound(p);
            if (lb != table.begin()) {
                --lb;
                while (lb != table.begin() && lb -> second <= q) {
                    lb = table.erase(lb);
                    --lb;
                }
                if (lb -> second <= q) table.erase(lb);
            }
            result += table.size();
        }
        cout << result << endl;
    }
    return 0;
}