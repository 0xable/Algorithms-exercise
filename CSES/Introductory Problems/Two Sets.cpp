// https://cses.fi/problemset/task/1092

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;
    long long totalSum = n * (n + 1) / 2;
    if (totalSum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int half = n / 2;
    int i = 1;
    vector<int> first;
    vector<int> second;
    if (n % 2 != 0) {
        i = 2;
        second.push_back(n);
        first.push_back(1);
        first.push_back(n - 1);
    } else {
        ++n;
    }

    for (; i <= half; ++i) {
        if ((i & 1) == 1) {
            first.push_back(i);
            first.push_back(n - i);
        } else {
            second.push_back(i);
            second.push_back(n - i);
        }
    }
    
    ostream_iterator<int> oi(cout, " ");
    cout << first.size() << endl;
    std::copy(first.begin(), first.end(), oi);
    cout << endl;
    cout << second.size() << endl;
    std::copy(second.begin(), second.end(), oi);
    cout << endl;

    return 0;
}