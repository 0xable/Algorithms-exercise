// https://cses.fi/problemset/task/1645

#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> numbers(n + 1);
    vector<int> result(n + 1);
 
    for (int i = 1, temp; i <= n; ++i) {
        cin >> numbers[i];
    }
 
    stack<pair<int, int>> small;
    result[1] = 0;
    small.push({numbers[1], 1});
    bool search;
    for (int i = 2; i <= n; ++i) {
        search = false;
        while (!small.empty()) {
            if (small.top().first < numbers[i]) {
                result[i] = small.top().second;
                small.push({numbers[i], i});
                search = true;
                break;
            }
            small.pop();
        }
        if (!search) {
            result[i] = 0;
            small.push({numbers[i], i});
        }
    }
 
    ostream_iterator<int> oi(cout, " ");
    auto begins = result.begin();
    begins++;
    std::copy(begins, result.end(), oi);
    return 0;
}