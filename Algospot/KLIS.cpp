// https://algospot.com/judge/problem/read/KLIS
// 구종만, 알고리즘 문제 해결 전략, 인사이트, 2012, p299 - 306 참조

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

class Solution {
    int n, k;
    int lisLength;
    int INF;
    vector<int> sequence;
    vector<int> lis;
    vector<int> count;
    
public:
    Solution(int n, int k, vector<int>& seq) : n{n}, k{k}, sequence{seq} {
        lis.assign(n + 1, -1);
        count.assign(n + 1, -1);
        INF = numeric_limits<int>::max();
        preProcess();
    }

    void preProcess() {
        lisProcess(-1);
        lisLength = lis[0] - 1;
        countProcess(-1);
    }

    int lisProcess(int start) {
        if (lis[start + 1] != -1) return lis[start + 1];
        int result = 1;
        for (int next = start + 1; next < n; ++next) {
            if (start == -1 || sequence[start] < sequence[next]) {
                result = std::max(result, lisProcess(next) + 1);
            }
        }
        return lis[start + 1] = result;
    }

    int countProcess(int start) {
        if (count[start + 1] != -1) return count[start + 1];
        if (lisProcess(start) == 1) return count[start + 1] = 1;
        int result = 0;
        for (int next = start + 1; next < n; ++next) {
            if ((start == -1 || sequence[start] < sequence[next]) && lisProcess(start) == lisProcess(next) + 1) {
                result = std::min<long long>(INF, (long long) result + countProcess(next));
            }
        }
        return count[start + 1] = result;
    }

    void process(int start, int k, vector<int>& result) {
        if (start != -1) result.push_back(sequence[start]);
        if (lis[start + 1] == 1) return;

        vector<pair<int, int>> nextOrder;
        for (int next = start + 1; next < n; ++next) {
            if ((start == -1 || sequence[start] < sequence[next]) && lisProcess(start) == lisProcess(next) + 1) {
                nextOrder.push_back(make_pair(sequence[next], next));
            }
        }
        std::sort(nextOrder.begin(), nextOrder.end());

        for (auto p : nextOrder) {
            if (count[p.second + 1] >= k) {
                process(p.second, k, result);
                return;
            } else {
                k -= count[p.second + 1];
            }
        }
    }
    
    vector<int> search() {
        vector<int> result;
        process(-1, k, result);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> sequence(n);
        for (int i = 0; i < n; ++i) {
            cin >> sequence[i];
        }
        Solution s(n, k, sequence);
        vector<int> result = s.search();

        ostream_iterator<int> oi(cout, " ");
        cout << result.size() << endl;
        std::copy(result.begin(), result.end(), oi);
        cout << endl;
    }
    return 0;
}