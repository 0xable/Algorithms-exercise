// https://cses.fi/problemset/task/1083

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;
    long long i;
    --n;
    while (n--) {
        cin >> i;
        sum -= i;
    }
    cout << sum << endl;
    return 0;
}