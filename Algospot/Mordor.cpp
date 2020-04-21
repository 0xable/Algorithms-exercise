// https://algospot.com/judge/problem/read/MORDOR

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class SegmentTree {
    int n;
    int size;
    // pair.first 구간 최소, pair.second 구간 최대
    vector<pair<int, int>> range;

public:
    SegmentTree(const vector<int>& input) {
        n = input.size();
        size = n;
        while ((size & (-size)) != size) {
            size += (size & -size);
        }
        size *= 2;
        range.resize(size);
        init(input, 0, n - 1, 1);
    }

    pair<int, int> init(const vector<int>& input, int left, int right, int node) {
        if (left == right) return range[node] = make_pair(input[left], input[left]);
        int mid = (left + right) / 2;
        pair<int, int> leftResult = init(input, left, mid, node * 2);
        pair<int, int> rightResult = init(input, mid + 1, right, node * 2 + 1);
        return range[node] = make_pair(std::min(leftResult.first, rightResult.first), std::max(leftResult.second, rightResult.second));
    }

    pair<int, int> query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) return make_pair(numeric_limits<int>::max(), numeric_limits<int>::min());
        if (left <= nodeLeft && nodeRight <= right) return range[node];
        if (nodeLeft == nodeRight) return range[node];
        
        int mid = (nodeLeft + nodeRight) / 2;
        auto leftResult = query(left, right, node * 2, nodeLeft, mid);
        auto rightResult = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return make_pair(std::min(leftResult.first, rightResult.first), std::max(leftResult.second, rightResult.second));
    }

    pair<int, int> query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, c;
        cin >> n >> c;
        vector<int> data(n);
        for (int i = 0; i < n; ++i) {
            cin >> data[i];
        }

        SegmentTree st(data);
        int left, right;
        while (c--) {
            cin >> left >> right;
            auto k = st.query(left, right);
            cout << k.second - k.first << endl;
        }
    }
    return 0;
}