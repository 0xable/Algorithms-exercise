// https://cses.fi/problemset/task/1090

#include <iostream>
#include <deque>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, x;
    cin >> n >> x;
    deque<int> children(n);
    for (int i = 0; i < n; ++i) {
        cin >> children[i];
    }
 
    int count = 0;
    int weight;
    std::sort(children.begin(), children.end());
    while (children.size() >= 2) {
        if (children.front() + children.back() <= x) {
            children.pop_front();
            children.pop_back();
            ++count;
        } else {
            children.pop_back();
            ++count;
        }
    }
    if (!children.empty()) ++count;
    
    cout << count << endl;
    return 0;
}