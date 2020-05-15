// https://algospot.com/judge/problem/read/PI

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int length;
    const int INF;
    string str;
    vector<int> cache;

public:
    Solution(int n, string input) : length{n}, str{input}, cache(n + 1, -1), INF{987654321} {

    }

    bool level1(const string& input) {
        for (int i = 1; i < input.length(); ++i) {
            if (input[i] != input[i - 1]) return false;
        }
        return true;
    }

    bool level2(const string& input) {
        int i = 1;
        while (i < input.length()) {
            if (input[i] != input[i - 1] + 1) break;
            ++i;
        }
        if (i == input.length()) return true;

        i = 1;
        while (i < input.length()) {
            if (input[i] != input[i - 1] - 1) break;
            ++i;
        }
        return i == input.length() ? true : false;
    }

    bool level3(const string& input) {
        char odd = input[0];
        char even = input[1];
        for (int i = 2; i < input.length(); ++i) {
            if (i % 2 == 0) {
                if (input[i] != odd) return false;
            } else {
                if (input[i] != even) return false;
            }
        }
        return true;
    }

    bool level4(const string& input) {
        int step = input[1] - input[0];
        for (int i = 2; i < input.length(); ++i) {
            if (input[i] != input[i - 1] + step) return false;
        }
        return true;
    }

    int getDifficulty(const string& input) {
        if (input.length() < 3) return INF;
        if (level1(input)) return 1;
        if (level2(input)) return 2;
        if (level3(input)) return 4;
        if (level4(input)) return 5;
        return 10;
    }

    int search(int i) {
        if (i >= length) return 0;
        if (cache[i] != -1) return cache[i];
        int result = INF;

        if (i + 2 < length) result = std::min(result, search(i + 3) + getDifficulty(str.substr(i, 3)));
        if (i + 3 < length) result = std::min(result, search(i + 4) + getDifficulty(str.substr(i, 4)));
        if (i + 4 < length) result = std::min(result, search(i + 5) + getDifficulty(str.substr(i, 5)));
        return cache[i] = result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        string input;
        cin >> input;
        Solution s(input.length(), input);
        cout << s.search(0) << endl;
    }
    return 0;
}