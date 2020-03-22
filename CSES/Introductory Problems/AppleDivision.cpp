// https://cses.fi/problemset/task/1623

#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
class Grouping {
private:
    int answer;
    int n;
    vector<long long> apples;
 
public:
    Grouping() {
        cin >> n;
        apples.reserve(8);
 
        for (int i = 0; i < n; ++i) {
            cin >> apples[i];
        }
        answer = INT_MAX;
    }
 
    void search(int count, long long sum1, long long sum2) {
        if (count == n) {
            long long temp = abs(sum1 - sum2);
 
            if (temp < answer) {
                answer = temp;
            }
            return;
        }
        search(count + 1, sum1 + apples[count], sum2);
        search(count + 1, sum1, sum2 + apples[count]);
    }
 
    void getAnswer() {
        cout << answer << endl;
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    Grouping g;
    g.search(0, 0, 0);
    g.getAnswer();
    return 0;
}