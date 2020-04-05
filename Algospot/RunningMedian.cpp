// https://algospot.com/judge/problem/read/RUNNINGMEDIAN

#include <iostream>
#include <queue>
#include <functional>

using namespace std;

class NextNumber {
    int a, b;
    long long prev;
    long long mod = 20090711;
public:
    NextNumber(int a, int b) : a{a}, b{b} {
        prev = 1983;
    }

    int next() {
        return prev = (prev * a + b) % mod;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, a, b;
        cin >> n >> a >> b;
        long long res = 1983;
        NextNumber num(a, b);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int, vector<int>, less<int>> maxHeap;
        maxHeap.push(1983);
        
        for (int i = 1; i < n; ++i) {
            if (minHeap.size() == maxHeap.size()) {
                maxHeap.push(num.next());
            } else {
                minHeap.push(num.next());
            }
            
            if (minHeap.top() < maxHeap.top()) {
                int t1 = minHeap.top();
                minHeap.pop();
                int t2 = maxHeap.top();
                maxHeap.pop();

                maxHeap.push(t1);
                minHeap.push(t2);
            }
            res = (res + maxHeap.top()) % 20090711LL;
        }
        cout << res << endl;
    }
    return 0;
}