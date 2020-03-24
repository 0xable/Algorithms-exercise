// https://algospot.com/judge/problem/read/STRJOIN

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0, c; i < n; ++i) {
            cin >> c;
            q.push(c);
        }
        int temp;
        int cost = 0;
        while (q.size() >= 2) {
            temp = q.top();
            q.pop();
            temp += q.top();
            q.pop();
            q.push(temp);
            cost += temp;
        }
        cout << cost << endl;
    }
    return 0;
}