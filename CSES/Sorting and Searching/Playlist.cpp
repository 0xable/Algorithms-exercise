// https://cses.fi/problemset/task/1141

#include <iostream>
#include <vector>
#include <queue>
#include <set>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> playlist(n);
    for (int i = 0; i < n; ++i) {
        cin >> playlist[i];
    }
 
    int max = 0;
    int count = 0;
    int base = 0;
    int curr;
    set<int> check;
    queue<int> includelist;
    for (int i = 0; i < n; ++i) {
        curr = playlist[i];
        includelist.push(curr);
 
        if (check.count(curr)) {
            while (includelist.front() != curr) {
                check.erase(includelist.front());
                includelist.pop();
                --count;
            }
            includelist.pop();
        } else {
            check.insert(curr);
            ++count;
            if (max < count) max = count;
        }
    }
    cout << max << endl;
    return 0;
}