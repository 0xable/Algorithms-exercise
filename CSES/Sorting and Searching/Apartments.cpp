// https://cses.fi/problemset/task/1084

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<int> demands(n);
    vector<int> provide(m);
    for (int i = 0; i < n; ++i) {
        cin >> demands[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> provide[i];
    }
 
    std::sort(demands.begin(), demands.end());
    std::sort(provide.begin(), provide.end());
 
    int count = 0;
    auto demand = demands.begin();
    auto provision = provide.begin();
    while (demand != demands.end() && provision != provide.end()) {
        if (*provision - k > *demand) {
            demand++;
            continue;
        }
        if (*demand > *provision + k) {
            ++provision;
            continue;
        }
        ++count;
        ++demand;
        ++provision;
    }
    cout << count << endl;
    return 0;
}