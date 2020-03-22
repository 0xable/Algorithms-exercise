// https://cses.fi/problemset/task/1755

#include <iostream>
#include <map>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    string input;
    cin >> input;
 
    map<char, string> counter;
    int length = input.length();
    for (auto ch : input) {
        if (counter.count(ch)) {
            counter[ch] += ch;
        } else {
            counter[ch] = ch;
        }
    }
 
    string odd = "";
    for (auto p : counter) {
        if (p.second.length() % 2 == 1) {
            if (odd != "") {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
            odd = p.first;
        }
    }
 
    string first = "";
    string last = "";
    for (auto p : counter) {
        first = first + p.second.substr(0, p.second.length() / 2);
        last = p.second.substr(0, p.second.length() / 2) + last;
    }
    cout << first << odd << last << endl;
    return 0;
}