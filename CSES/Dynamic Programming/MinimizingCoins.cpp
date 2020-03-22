// https://cses.fi/problemset/task/1634/

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
 
    vector<int> cases(target + 1, -1);
    for (auto coin : coins) {
        for (int i = 1; i <= target; ++i) {
            if (i == coin) {
                cases[i] = 1;
            } else if (i - coin > 0 && cases[i - coin] != -1) {
                if (cases[i] == -1) {
                    cases[i] = cases[i - coin] + 1;
                } else {
                    cases[i] = std::min(cases[i - coin] + 1, cases[i]);
                }
            }
        }
    }
 
    cout << cases[target] << endl;
    return 0;
}