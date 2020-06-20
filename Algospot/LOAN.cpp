// https://algospot.com/judge/problem/read/LOAN
// 0 ms

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int m;
        double n, p;
        cin >> n >> m >> p;

        // n * r ^ m = c * (r ^ (m - 1) + r ^ (m - 2) + ... + r ^ 2 + r ^ 1 + r ^ 0)
        double r = 1 + ((p / 100) / 12);
        double right = 0;
        double exponent = 1;
        for (int i = 0; i < m; ++i) {
            right += exponent;
            exponent *= r;
        }
        double left = n * exponent;

        cout << setprecision(12) << std::fixed;
        cout << left / right << endl;
    }
    return 0;
}