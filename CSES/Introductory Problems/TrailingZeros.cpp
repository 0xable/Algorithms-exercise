// https://cses.fi/problemset/task/1618

#include <iostream>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
 
    int numFactorFive = 0;
    int fiveExp = 5;
    int temp;
    while (fiveExp <= n) {
        temp = n / fiveExp;
        numFactorFive += temp;
        fiveExp *= 5;
    }
    
    cout << numFactorFive << endl;
    return 0;
}