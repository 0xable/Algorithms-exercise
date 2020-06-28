// https://algospot.com/judge/problem/read/PASS486
// 구종만, 알고리즘 문제 해결 전략, 인사이트, 2012, p500 - 506 참조
// 2476 ms

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int upper = 10000000;
    int sqrtn = sqrt(upper);
    // minFactor[i] = i 의 가장 작은 소인수
    vector<int> minFactor(upper + 1);
    // minFactorPower[i] = i 의 소인수 분해에는 minFactor[i] 의 몇 승이 포함되어 있는가?
    vector<int> minFactorPower(upper + 1);
    // factors[i] = i 가 가진 약수의 수
    vector<int> factors(upper + 1);
    factors[1] = 1;
    for (int i = 0; i <= upper; ++i) minFactor[i] = i;

    for (int i = 2; i <= sqrtn; ++i) {
        if (minFactor[i] != i) continue;
        for (int j = i * i; j <= upper; j += i) {
            if (minFactor[j] == j) minFactor[j] = i;
        }
    }

    for (int n = 2; n <= upper; ++n) {
        if (minFactor[n] == n) { // 소수인 경우
            minFactorPower[n] = 1;
            factors[n] = 2;
        } else { // 소수가 아닌 경우
            int p = minFactor[n];
            int m = n / p;

            if (p != minFactor[m]) { // m 이 p 로  더이상 나누어지지 않는 경우
                minFactorPower[n] = 1;
            } else {
                minFactorPower[n] = minFactorPower[m] + 1;
            }
            int a = minFactorPower[n];
            factors[n] = (factors[m] / a) * (a + 1);
        }
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int k, l, h;
        cin >> k >> l >> h;

        int result = 0;
        for (int i = l; i <= h; ++i) {
            if (factors[i] == k) ++result;
        }
        cout << result << endl;
    }
    return 0;
}