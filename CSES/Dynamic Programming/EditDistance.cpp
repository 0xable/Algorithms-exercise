// https://cses.fi/problemset/task/1639

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    string from, to;
    cin >> from >> to;
 
    int fromLength = from.length();
    int toLength = to.length();
    vector<vector<int>> lcs2(fromLength, vector<int>(toLength, 0));
    int count;
    bool flag = false;
    for (int i = 0; i < fromLength; ++i) {
        if (flag) {
            lcs2[i][0] = i;
        } else {
            if (from[i] == to[0]) {
                lcs2[i][0] = i;
                flag = true;
            } else {
                lcs2[i][0] = i + 1;
            }
        }
    }
    flag = false;
    for (int j = 0; j < toLength; ++j) {
        if (flag) {
            lcs2[0][j] = j;
        } else {
            if (from[0] == to[j]) {
                lcs2[0][j] = j;
                flag = true;
            } else {
                lcs2[0][j] = j + 1;
            }
        }
    }
 
    for (int i = 1; i < fromLength; ++i) {
        for (int j = 1; j < toLength; ++j) {
            if (from[i] == to[j]) {
                lcs2[i][j] = lcs2[i - 1][j - 1];
            } else {
                int temp = std::min(lcs2[i - 1][j], lcs2[i][j - 1]);
                lcs2[i][j] = std::min(lcs2[i - 1][j - 1], temp) + 1;
            }
        }
    }
 
    int answer = lcs2[fromLength - 1][toLength - 1];
    cout << answer << endl;
    return 0;
}