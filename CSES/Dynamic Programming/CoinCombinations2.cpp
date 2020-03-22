// https://cses.fi/problemset/task/1636

#include <iostream>
#include <vector>
 
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
 
    vector<int> cases(target + 1, 0);
    for (auto coin : coins) {
        for (int i = 1; i <= target; ++i) {
            if (i < coin) continue;
            if (i == coin) {
                cases[i] += 1;
            } else {
                if (cases[i - coin] > 0) {
                    cases[i] = (cases[i] + cases[i - coin]) % 1000000007;
                }
            }
        }
    }
 
    cout << cases[target] << endl;
    return 0;
}