// https://algospot.com/judge/problem/read/JAEHASAFE

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void setTable(string& str, vector<int>& res) {
    int size = str.length();
    int begin = 1, matched = 0;
    while (begin + matched < size) {
        if (str[begin + matched] == str[matched]) {
            ++matched;
            res[begin + matched - 1] = matched;
        } else {
            if (matched == 0) {
                ++begin;
            } else {
                begin += matched - res[matched - 1];
                matched = res[matched - 1];
            }
        }
    }
}

int getShiftLocation(string& target, string& pattern) {
    int size = pattern.length();
    vector<int> table(size, 0);
    
    setTable(pattern, table);
    int begin = 0, matched = 0;
    int length = size * 2;
    while (begin + matched < length) {
        if (target[begin + matched] == pattern[matched]) {
            ++matched;
            if (matched == size) return begin;
        } else {
            if (matched == 0) {
                ++begin;
            } else {
                begin += matched - table[matched - 1];
                matched = table[matched - 1];
            }
        }
    }
    return begin;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string prev, next;
        
        cin >> prev;
        int count = 0;
        int size = prev.length();
        vector<int> table(size, 0);
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> next;
            table.assign(size, 0);
            if (flag) {
                string temp = prev + prev;
                count += getShiftLocation(temp, next);
            } else {
                string temp = next + next;
                count += getShiftLocation(temp, prev);
            }
            flag ^= 1;
            prev = std::move(next);
        }
        cout << count << endl;
    }
    return 0;
}