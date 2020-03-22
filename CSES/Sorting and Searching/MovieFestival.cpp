// https://cses.fi/problemset/task/1629

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<pair<int, int>> timetable(n);
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        timetable[i] = {a, b};
    }
 
    std::sort(timetable.begin(), timetable.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second < b.second) {
            return true;
        } else if (a.second > b.second) {
            return false;
        } else {
            return a.first < b.first;
        }
    });
 
    auto iter = timetable.begin();
    int count = 1;
    int prevEndTime = (*iter).second;
    ++iter;    
    while (iter != timetable.end()) {
        if ((*iter).first >= prevEndTime) {
            ++count;
            prevEndTime = (*iter).second;
        }
        ++iter;
    }
    cout << count << endl;
    return 0;
}