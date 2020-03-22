// https://cses.fi/problemset/task/1641

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
    numbers[0] = {0, 0};
    for (int i = 1, temp; i <= n; ++i) {
        cin >> temp;
        numbers[i] = {temp, i};
    }
    std::sort(numbers.begin(), numbers.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
 
    int front, rear, elem;
    for (int i = 1; i <= n; ++i) {
        front = 1;
        rear = n;
        elem = numbers[i].first;
        while (front < rear) {
            if (front == i) {
                front++;
                continue;
            }
            if (rear == i) {
                rear--;
                continue;
            }
            if (elem + numbers[front].first + numbers[rear].first > x) {
                rear--;
            } else if (elem + numbers[front].first + numbers[rear].first < x) {
                front++;
            } else {
                cout << numbers[i].second << " " << numbers[front].second << " " << numbers[rear].second << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}