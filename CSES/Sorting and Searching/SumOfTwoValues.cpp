// https://cses.fi/problemset/task/1640

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> numbers(n + 1);
    for (int i = 1, temp; i <= n; ++i) {
        cin >> temp;
        numbers[i] = {temp, i};
    }
    if (n == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    std::sort(numbers.begin(), numbers.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    int front = 1;
    int rear = n;
    while (front < rear) {
        if (numbers[front].first + numbers[rear].first == x) {
            cout << numbers[front].second << " " << numbers[rear].second << endl;
            return 0;
        } else if (numbers[front].first + numbers[rear].first > x) {
            --rear;
        } else {
            ++front;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}