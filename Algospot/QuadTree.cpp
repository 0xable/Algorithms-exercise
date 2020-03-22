https://algospot.com/judge/problem/read/QUADTREE

#include <iostream>
#include <string>

using namespace std;

string split(string::iterator& it) {
    if (*it == 'x') {
        string ul = split(++it);
        string ur = split(++it);
        string ll = split(++it);
        string lr = split(++it);
        return "x" + ll + lr + ul + ur;
    } else {
        char s = *it;
        return string{s};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    
    while (tc--) {
        string input;
        cin >> input;
        auto it = input.begin();
        cout << split(it) << endl;
    }
    return 0;
}