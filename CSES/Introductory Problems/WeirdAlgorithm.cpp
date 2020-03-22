// https://cses.fi/problemset/task/1068/

#include <iostream>
#include <iterator>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    long long n;
    cin >> n;
    ostream_iterator<long long> oi(cout, " ");
    oi = n;
    while (n != 1) {
        if (n & 1) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        oi = n;
    }
    return 0;
}