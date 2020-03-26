#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    vector<int> sieve(10000001, 0);
    vector<int> factor(10000001, 2);
    for (long long i = 2; i < 10000001; ++i) {
        for (long long j = i + i; j < 10000001; j += i) {
            ++factor[j];
        }
    }

    while (tc--) {
        int n, low, high;
        int result = 0;
        cin >> n >> low >> high;
        
        while (low <= high) {
            if (factor[low] == n) result++;
            ++low;
        }
        cout << result << endl;
    }
    return 0;
}