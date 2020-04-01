// https://algospot.com/judge/problem/read/NAMING

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> getPartialMatch(const string& pattern) {
    int n = pattern.length();
    vector<int> res(n, 0);
    int begin = 1, matched = 0;

    while (begin + matched < n) {
        if (pattern[begin + matched] == pattern[matched]) {
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

    string a, b;
    cin >> a >> b;

    string str = a + b;
    int n = str.length();

    vector<int> table = getPartialMatch(str);
    vector<int> res;
    res.push_back(n);

    int begin = 1;
    int matched = 0;
    while (begin < n) {
        while (begin + matched < n) {
            if (str[begin + matched] == str[matched]) {
                ++matched;
            } else {
                if (matched == 0) {
                    begin++;
                } else {
                    begin += matched - table[matched - 1];
                    matched = table[matched - 1];
                }
            }
        }

        if (begin + matched == n && matched) res.push_back(matched);
        begin += matched - table[matched - 1];
        matched = table[matched - 1];
    }
    ostream_iterator<int> oi(cout, " ");
    std::copy(res.rbegin(), res.rend(), oi);
    return 0;
}