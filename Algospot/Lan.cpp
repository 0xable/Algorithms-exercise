// https://algospot.com/judge/problem/read/LAN

#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

class UnionFind {
    int n;
    vector<int> root;
    vector<int> depth;
    vector<int> size;
public:
    UnionFind(int n) : n{n}, root(n), depth(n), size(n) {
        for (int i = 0; i < n; ++i) {
            root[i] = i;
            depth[i] = 1;
            size[i] = 1;
        }
    }

    int getRoot(int n) {
        if (root[n] == n) return n;
        return root[n] = getRoot(root[n]);
    }

    int merge(int i, int j) {
        i = getRoot(i);
        j = getRoot(j);
        if (i == j) return i;
        if (depth[i] > depth[j]) {
            std::swap(i, j);
        }
        if (depth[i] == depth[j]) depth[j]++;
        size[j] += size[i];
        root[i] = j;
        return j;
    }

    int getSize(int n) {
        return size[n];
    }
};

class Solution {
    int n;
    double totalCost;
    UnionFind uf;
    vector<tuple<int, int, int>> q;
    
public:
    Solution(int n, vector<tuple<int, int, int>>& q, UnionFind uf) : n{n}, q{q}, uf{uf}, totalCost{0} {

    }

    void search() {
        int src, des;
        double cost;
        while (!q.empty()) {
            std::tie(cost, src, des) = q.back();
            q.pop_back();
            if (uf.getRoot(src) == uf.getRoot(des)) continue;
            totalCost += std::sqrt(cost);
            int k = uf.merge(src, des);
            if (uf.getSize(k) == n) break;
        }
    }

    double getResult() {
        return totalCost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<int> nodex(n);
        vector<int> nodey(n);
        for (int i = 0; i < n; ++i) {
            cin >> nodex[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> nodey[i];
        }

        vector<tuple<int, int, int>> q;
        int dist, deltaX, deltaY;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                deltaX = nodex[i] - nodex[j];
                deltaY = nodey[i] - nodey[j];
                dist = (deltaX * deltaX) + (deltaY * deltaY);
                q.push_back(make_tuple(dist, i, j));
            }
        }
        std::sort(q.begin(), q.end(), greater<tuple<int, int, int>>());

        UnionFind u(n);
        int src, des;
        for (int i = 0; i < m; ++i) {
            cin >> src >> des;
            u.merge(src, des);
        }
        
        Solution s(n, q, u);
        s.search();
        cout << std::fixed << std::setprecision(12);
        cout << s.getResult() << endl;
    }
    return 0;
}