// https://cses.fi/problemset/task/1620

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
 
using namespace std;
 
class Solution {
    vector<int> machines;
    int n, t;
public:
    Solution(int n, int t, vector<int>&& machines) : n{n}, t{t}, machines{machines} {}
 
    bool isPossible(long long time) {
        long long output = 0;
        for (int i = 0; i < n; ++i) {
            output += time / machines[i];
            if (output >= t) return true;
        }
        return false;
    }
 
    long long search() {
        long long iter = 0;
        for (long long step = std::numeric_limits<long long>::max(); step >= 1; step /= 2) {
            while (!isPossible(iter + step)) iter += step;
        }
        return iter + 1;
    }    
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, t;
    cin >> n >> t;
    vector<int> machines(n);
    for (int i = 0; i < n; ++i) {
        cin >> machines[i];
    }
    Solution s(n, t, std::move(machines));
    cout << s.search() << endl;
    return 0;
}