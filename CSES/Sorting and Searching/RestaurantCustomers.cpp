// https://cses.fi/problemset/task/1619

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> arrival(n);
    vector<int> leave(n);
 
    for (int i = 0; i < n; ++i) {
        cin >> arrival[i] >> leave[i];
    }
    std::sort(arrival.begin(), arrival.end());
    std::sort(leave.begin(), leave.end());
    
    int max = -1;
    int count = 0;
    auto entrance = arrival.begin();
    auto gone = leave.begin();
    while (entrance != arrival.end() ) {
        if (*entrance < *gone) {
            count++;
            entrance++;
            if (max < count) max = count;
        } else {
            count--;
            gone++;
        }
    }
 
    cout << max << endl;
    return 0;
}