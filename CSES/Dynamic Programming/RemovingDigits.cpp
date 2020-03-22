// https://cses.fi/problemset/task/1637

#include <iostream>
#include <vector>
#include <limits>
 
using namespace std;
 
class Solution {
private:
    int n;
    vector<int> table;
    vector<int> ready;
public:
    Solution(int n) {
        this -> n = n;
        table.assign(n + 1, 0);
        ready.assign(n + 1, false);
        int init = n > 9 ? 9 : n;
        for (int i = 1; i <= init; ++i) {
            table[i] = 1;
            ready[i] = true;
        }
    }
 
    int search(int n) {
        if (ready[n]) {
            return table[n];
        }
        vector<int> searchList;
        int digit;
        int num = n;
        while (num > 0) {
            digit = num % 10;
            num /= 10;
            if (digit == 0) continue;
            searchList.push_back(digit);
        }
        int min = std::numeric_limits<int>::max();
        int temp;
        for (auto i : searchList) {
            temp = search(n - i);
            if (temp < min) min = temp;
        }
        ready[n] = true;
        table[n] = min + 1;
        return table[n];
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    Solution s(n);
    cout << s.search(n) << endl;
    return 0;
}
