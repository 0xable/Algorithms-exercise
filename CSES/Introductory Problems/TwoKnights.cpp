// https://cses.fi/problemset/task/1072

#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    
    vector<long long> result(n + 1);
    result[1] = 0;
    result[2] = 6;
 
 
    long long notApplicable = 6;
    long long addedCell = 5;
    for (int i = 3; i <= n; ++i) {
        long long intersect = (i - 1) * (i - 1) * addedCell;
        intersect -= notApplicable;
        
        long long other = addedCell * (addedCell - 1) / 2 - 2;
        result[i] = result[i - 1] + intersect + other;
        addedCell += 2;
        notApplicable += 8;
    }
 
    for (int i = 1; i <= n; ++i) {
        cout << result[i] << "\n";
    }
    return 0;
}