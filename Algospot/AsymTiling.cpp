// https://algospot.com/judge/problem/read/ASYMTILING

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> table(101);
    table[1] = 1;
    table[2] = 2;
    for (int i = 3; i <= 100; ++i) {
        table[i] = (table[i - 1] + table[i - 2]) % 1000000007;
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        if (n <= 2) {
            cout << 0 << endl;
            continue;
        }
        int result = table[n] - table[n / 2];
        if (n % 2 == 0) result -= table[n / 2 - 1];
        while (result < 0) result += 1000000007;
        cout << result << endl;
    }
    return 0;
}