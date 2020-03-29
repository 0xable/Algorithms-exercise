// https://algospot.com/judge/problem/read/ITES

#include <iostream>
#include <deque>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    constexpr long long mod = std::numeric_limits<unsigned int>::max() + 1ll;

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> k >> n;
        deque<long long> signal = {1983};
        int sum = 0;
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            sum += signal.back() % 10000 + 1;
            long long temp = (signal.back() * 214013 + 2531011) % mod;
            signal.push_back(temp);
            
            while (sum >= k) {
                if (sum == k) ++answer;
                sum -= (signal.front() % 10000 + 1);
                signal.pop_front();
            }
        }
        cout << answer << endl;
    }
    return 0;
}