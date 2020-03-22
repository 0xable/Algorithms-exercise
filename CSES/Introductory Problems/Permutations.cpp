// https://cses.fi/problemset/task/1070/

#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
 
    if (n == 1) {
        cout << "1";
        return 0;
    }
    if (n <= 3) {
        cout << "NO SOLUTION";
        return 0;
    }
    
    int i = 2;
    while (i <= n) {
        cout << i << " ";
        i += 2;
    }
    i = 1;
    while (i <= n) {
        cout << i << " ";
        i += 2;
    }
    return 0;
}