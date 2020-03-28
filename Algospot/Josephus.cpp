// https://algospot.com/judge/problem/read/JOSEPHUS

#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        list<int> m;
        for (int i = 1; i <= n; ++i) {
            m.push_back(i);
        }
        
        int remain = n - 2;
        auto it = m.begin();
        it = m.erase(it);
        remain--;
        while (remain--) {
            for (int i = 1; i < k; ++i) {
                it++;
                if (it == m.end()) it = m.begin();
            }
            it = m.erase(it);
            if (it == m.end()) it = m.begin();
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}