// https://algospot.com/judge/problem/read/TILING2

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    vector<int> cache(101);
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;
    for (int i = 3; i <= 100; ++i) {
        cache[i] = (cache[i - 1] + cache[i - 2]) % 1000000007;
    }
    while (tc--) {
        int n;
        cin >> n;
        cout << cache[n] << endl;
    }
    return 0;
}