// https://algospot.com/judge/problem/read/DRAGON
// 구종만, 알고리즘 문제 해결 전략, 인사이트, 2012, p306 - 312 참조
// 0 ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> length;
    const int INF;
    const string EXPAND_X;
    const string EXPAND_Y;
public:
    Solution() : INF{1000000001}, EXPAND_X{"X+YF"}, EXPAND_Y{"FX-Y"} {
        length.assign(51, 0);
        length[0] = 1;
        for (int i = 1; i < 51; ++i) {
            length[i] = std::min(length[i - 1] * 2 + 2, INF);
        }
    }

    // generations 세대 skip 번째 문자 반환
    char expand(const string& dragonCurve, int generations, int skip) {
        if (generations == 0) {
            // assert(skip < dragonCurve.size());
            return dragonCurve[skip];
        }
        for (int i = 0; i < dragonCurve.size(); ++i) {
            // 문자열이 확장되는 경우
            if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
                if (skip >= length[generations]) {
                    skip -= length[generations];
                } else if (dragonCurve[i] == 'X') {
                    return expand(EXPAND_X, generations - 1, skip);
                } else {
                    return expand(EXPAND_Y, generations - 1, skip);
                }
            } else if (skip > 0) {
                // 확장되진 않지만 건너 뛰어야 할 경우
                --skip;
            } else {
                // 답을 찾은 경우
                return dragonCurve[i];
            }
        }
        return '#'; // 이 라인이 실행되면 문제가 있음.
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    string base = "FX";

    int tc;
    cin >> tc;
    while (tc--) {
        int generations, skip, l;
        cin >> generations >> skip >> l;
        --skip;
        for (int i = 0; i < l; ++i) {
            cout << s.expand(base, generations, skip + i);
        }
        cout << endl;
    }
    return 0;
}