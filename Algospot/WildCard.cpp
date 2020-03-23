// https://algospot.com/judge/problem/read/WILDCARD

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

bool isMatch(string pattern, string param) {
    int patternLength = pattern.length();
    int paramLength = param.length();
    vector<vector<bool>> table(patternLength, vector<bool>(paramLength, false));

    if (pattern[0] == '*') {
        for (int i = 0; i < paramLength; ++i) {
            table[0][i] = true;
        }
    } else if (pattern[0] == '?' || pattern[0] == param[0]) {
        table[0][0] = true;
    }

    bool once = false;
    for (int i = 1; i < patternLength; ++i) {
        if (pattern[i] == '*') {
            table[i][0] = true;
        } else if (pattern[i] == '?' || pattern[i] == param[0]) {
            if (once) break;
            table[i][0] = true;
            once = true;
        } else {
            break;
        }
    }

    for (int i = 1; i < patternLength; ++i) {
        for (int j = 1; j < paramLength; ++j) {
            if (pattern[i] == '*') {
                table[i][j] = table[i - 1][j - 1] || table[i - 1][j] || table[i][j - 1];
            } else if (pattern[i] == '?' || pattern[i] == param[j]) {
                table[i][j] = table[i - 1][j - 1];
            } else {
                table[i][j] = false;
            }
        }
    }
    return table[patternLength - 1][paramLength - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        string pattern;
        cin >> pattern;
        int n;
        cin >> n;
        string input;
        set<string> result;
        while (n--) {
            cin >> input;
            if (isMatch(pattern, input)) {
                result.insert(input);
            }
        }

        auto it = result.begin();
        while (it != result.end()) {
            cout << *it << endl;
            it++;
        }
    }
    return 0;
}