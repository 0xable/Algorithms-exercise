// https://cses.fi/problemset/task/1643

#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
 
    long long max = -1234567890;
    long long partialsum = 0;
    for (int i = 0; i < n; ++i) {
        partialsum += numbers[i];
        if (max < partialsum) {
            max = partialsum;
        }
        if (partialsum < 0) {
            partialsum = 0;
        }
    }
    cout << max << endl;
    return 0;
}