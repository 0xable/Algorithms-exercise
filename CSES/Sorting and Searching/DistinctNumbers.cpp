// https://cses.fi/problemset/task/1621

#include <iostream>
#include <set>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    set<int> numbers;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        numbers.insert(temp);
    }
    cout << numbers.size() << endl;
    return 0;
}