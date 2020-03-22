// https://cses.fi/problemset/task/1754

#include <iostream>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
 
    int a, b;
    while (n--) {
        cin >> a >> b;
        if ((a + b) % 3 != 0) {
            cout << "NO" << endl;
        } else {
            if (a > 2 * b || 2 * a <  b) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}