// https://algospot.com/judge/problem/read/ZIMBABWE
// 구종만, 알고리즘 문제 해결 전략, 인사이트, 2012, p320 - 327 참조
// 720 ms ㅠ_ㅠ

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int n, m;
    vector<vector<vector<int>>> cache;
    string e;
    string digits;
public:
    Solution(string e, int m) : e{e}, m{m} {
        n = e.length();
        cache.assign(1 << n, vector<vector<int>>(m, vector<int>(2, -1)));
        digits = e;
        std::sort(digits.begin(), digits.end());
    }

    /*  
     *  digits : e 의 자릿수들을 정렬한 것
     *  index : 이번에 채울 자리의 인덱스
     *  taken : 지금까지 사용한 자릿수들의 집합
     *  mod : 지금까지 만든 가격의 m 에 대한 나머지
     *  less : 지금까지 만든 가격이 이미 e 보다 작으면 1, 아니면 0
     */
    int price(int index, int taken, int mod, int less) {
        // 기저 사례
        if (index == n) {
            return (less && mod == 0) ? 1 : 0;
        }
        
        if (cache[taken][mod][less] != -1) return cache[taken][mod][less];
        int result = 0;
        for (int next = 0; next < n; ++next) {
            if ((taken & (1 << next)) == 0) {
                // 과거 가격은 새 가격보다 항상 작아야만 한다.
                if (!less && e[index] < digits[next]) continue;

                // 같은 숫자는 한 번만 선택한다.
                if (next > 0 && digits[next - 1] == digits[next] && (taken & (1 << (next - 1))) == 0) continue;

                int nextTaken = taken | (1 << next);
                int nextMod = (mod * 10 + digits[next] - '0') % m;
                int nextLess = less || e[index] > digits[next];
                result += price(index + 1, nextTaken, nextMod, nextLess);
                result %= 1000000007;
            }
        }
        return cache[taken][mod][less] = result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        string e;
        int m;
        cin >> e >> m;
        Solution s(e, m);
        cout << s.price(0, 0, 0, 0) << endl;
    }
    return 0;
}