// https://cses.fi/problemset/task/1633

#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> cases(n + 1, 0);
    cases[0] = 1;
    vector<int> dice = {1, 2, 3, 4, 5, 6};
 
    for (int i = 1; i <= n; ++i) {
        for (auto num : dice) {
            if (i >= num) {
                cases[i] = (cases[i] + cases[i - num]) % 1000000007;
            }
        }
    }
    cout << cases[n] << endl;
    return 0;
}