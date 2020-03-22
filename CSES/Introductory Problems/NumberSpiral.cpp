// https://cses.fi/problemset/task/1071/

#include <iostream>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    long long x, y;
    long long max, search;
    while (t--) {
        cin >> x >> y;
        if (x > y) {
            search = x * x;
            if (x % 2 == 0) {
                search -= (y - 1);
            } else {
                search = search - (x - 1) - (x - y);
            }
        } else if (y > x) {
            search = y * y;
            if (y % 2 == 0) {
                search = search - (y - 1) - (y - x);
            } else {
                search -= (x - 1);
            }
        } else {
            search = x * x;
            search -= (x - 1);
        }
        cout << search << endl;
    }
    return 0;
}