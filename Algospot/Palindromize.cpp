// https://algospot.com/judge/problem/read/PALINDROMIZE

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getTable(string& str) {
    int n = str.size();
    vector<int> res(n, 0);
    int begin = 1;
    int matched = 0;
    while (begin + matched < n) {
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
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        string origin;
        cin >> origin;
        string reversed = string(origin.rbegin(), origin.rend());
        vector<int> table = getTable(reversed);
        int begin = 0;
        int matched = 0;
        int size = origin.length();
        int max = 0;

        while (begin < size) {
            if (origin[begin + matched] == reversed[matched]) {
                ++matched;
                if (begin + matched == size) break;
            } else {
                if (matched == 0) {
                    begin++;
                } else {
                    begin += matched - table[matched - 1];
                    matched = table[matched - 1];
                }
                
            }
        }
        cout << size * 2 - matched << endl;
    }
    return 0;
}