// https://algospot.com/judge/problem/read/SUSHI
// 구종만, 알고리즘 문제 해결 전략, 인사이트, 2012, p355 - 359 참조
// 슬라이딩 윈도우 적용, 4524 ms

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        m /= 100;
        vector<int> price(n);
        vector<int> prefer(n);
        vector<int> table(201, 0);
        
        for (int i = 0; i < n; ++i) {
            cin >> price[i] >> prefer[i];
            price[i] /= 100;
        }

        for (int i = 1; i <= m; ++i) {
            for (int k = 0; k < n; ++k) {
                if (i >= price[k]) {
                    table[i % 201] = std::max(table[i % 201], table[(i - price[k]) % 201] + prefer[k]);
                }
            }
        }
        cout << table[m % 201] << endl;
    }
    return 0;
}