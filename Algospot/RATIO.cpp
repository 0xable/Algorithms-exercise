// https://algospot.com/judge/problem/read/RATIO
// 0 ms

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        long long total, win;
        cin >> total >> win;
        int currRatio = win * 100 / total;
        if (currRatio >= 99) {
            cout << -1 << endl;
            continue;
        }
        long long step = 2000000000;
        long long result = 0;
        while (step) {
            while (currRatio == ((win + step) * 100 / (total + step))) {
                win += step;
                total += step;
                result += step;
            }
            step /= 2;
        }
        cout << result + 1 << endl;
    }
    return 0;
}