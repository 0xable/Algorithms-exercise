// https://cses.fi/problemset/task/1145

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    
    vector<int> tails;
    tails.push_back(seq[0]);
 
    int curr;
    for (int i = 1; i < n; ++i) {
        curr = seq[i];
        int index = 0;
        int step = tails.size();
        while (step) {
            while (index + step < tails.size() && tails[index + step] < curr) {
                index += step;
            }
            step /= 2;
        }
 
        if (index == 0 && curr <= tails[index]) {
            tails[index] = curr;
            continue;
        }
        ++index;
        if (index == tails.size()) {
            tails.push_back(curr);
        } else {
            tails[index] = curr;
        }
    }
    cout << tails.size() << endl;
    return 0;
}