// https://cses.fi/problemset/task/1617

#include <iostream>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
 
    int answer = 1;
    while (n--) {
        answer = (answer * 2) % 1000000007;
    }
    cout << answer << endl;
    return 0;
}