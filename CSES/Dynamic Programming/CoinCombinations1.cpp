// https://cses.fi/problemset/task/1635

#include <iostream>
#include <vector>
 
using namespace std;
 
class Solve {
private:
    int n, target;
 
    vector<int> coins;
    vector<int> cases;
    vector<bool> ready;
 
public:
    Solve(int n, int target) {
        this -> n = n;
        this -> target = target;
        coins.resize(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> coins[i];
        }
 
        cases.assign(target + 1, 0);
        ready.assign(target + 1, false);
        cases[0] = 1;
        ready[0] = true;
    }
 
    int search(int n) {
        if (ready[n]) {
            return cases[n];
        }
        for (auto coin : coins) {
            if (coin > n) continue;
            cases[n] = (search(n - coin) + cases[n]) % 1000000007;
        }
        ready[n] = true;
        return cases[n];
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, target;
    cin >> n >> target;
 
    Solve solve(n, target);
    cout << solve.search(target) << endl;
    return 0;
}