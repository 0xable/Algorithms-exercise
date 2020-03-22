// https://cses.fi/problemset/task/1069/

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string input;
    cin >> input;
    auto it = input.begin();
    char prev =  *it;
    it++;

    int cnt = 1;
    int max = 1;
    while (it != input.end()) {
        if (prev == *it) {
            ++cnt;
            if (max < cnt) max = cnt;
        } else {
            prev = *it;
            cnt = 1;
        }
        it++;
    }
    cout << max << endl;
    return 0;
}