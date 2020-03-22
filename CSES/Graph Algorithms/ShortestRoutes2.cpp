// https://cses.fi/problemset/task/1672

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m, q;
    constexpr long long INF = 987654321987654321;
    cin >> n >> m >> q;
    vector<vector<long long>> cost(n + 1, vector<long long>(n + 1, INF));
    for (int i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c;
        if (c < cost[a][b]) {
            cost[a][b] = cost[b][a] = c;
        }
    }
    vector<pair<int, int>> query(q);
    for (int i = 0, a, b; i < q; ++i) {
        cin >> a >> b;
        query[i] = {a, b};
    }
 
    for (int i = 1; i <= n; ++i) {
        cost[i][i] = 0;
    }
 
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (cost[i][j] > cost[i][k] + cost[k][j]) {
                    cost[i][j] = cost[j][i] = cost[i][k] + cost[k][j];
                }
            }
        }
    }
 
    for (int i = 0; i < q; ++i) {
        int a = query[i].first;
        int b = query[i].second;
        cout << (cost[a][b] == INF ? -1 : cost[a][b]) << '\n';
    }
    return 0;
}