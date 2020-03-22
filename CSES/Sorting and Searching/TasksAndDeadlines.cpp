// https://cses.fi/problemset/task/1630

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0, a, b; i < n; ++i) {
        cin >> a >> b;
        tasks[i] = {a, b};
    }
    std::sort(tasks.begin(), tasks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
 
    long long time = 0;
    long long reward = 0;
    for (auto task : tasks) {
        time += task.first;
        reward += task.second - time;
    }
    cout << reward << endl;
    return 0;
}