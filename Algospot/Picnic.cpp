// https://algospot.com/judge/problem/read/PICNIC

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
    int n, m;
    int count;
    vector<bool> mated;
    vector<vector<bool>> friends;
public:
    Solution(int n, int m, vector<vector<bool>>&& f) : n{n}, m{m}, friends{f} {
        mated.assign(n, false);
        count = 0;
    }

    void search(int matched, int first) {
        if (matched == n) {
            count++;
            return;
        }
        for (int i = first; i < n; ++i) {
            if (mated[i]) continue;
            for (int j = i + 1; j < n; ++j) {
                if (mated[j] || !friends[i][j]) continue;
                mated[i] = true;
                mated[j] = true;
                search(matched + 2, i + 1);
                mated[i] = false;
                mated[j] = false;
            }
        }
    }

    int getAnswer() {
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    int n, m;
    while (tc--) {
        cin >> n >> m;
        vector<vector<bool>> friends(n, vector<bool>(n, false));
        int a, b;
        while (m--) {
            cin >> a >> b;
            friends[a][b] = true;
            friends[b][a] = true;
        }
        Solution s(n, m, std::move(friends));
        s.search(0, 0);
        cout << s.getAnswer() << endl;
    }
    return 0;
}

int n;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
    int firstFree = -1;
    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1) return 1;
    int ret = 0;

    for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
        if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
}