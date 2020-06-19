// https://algospot.com/judge/problem/read/ROOTS
// 구종만, 알고리즘 문제 해결 전략, 인사이트, 2012, p472 - 474 참조
// 4 ms

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
    int n;
    vector<double> coefficient;

public:
    Solution(int n, vector<double>& coefficient) : n{n}, coefficient{coefficient} {

    }

    vector<double> solveNaive(const vector<double>& poly) {
        int k = poly.size();
        if (k == 2) return { -(poly[0] / poly[1]) };

        vector<double> result;
        double determinant = sqrt(poly[1] * poly[1] - 4 * poly[2] * poly[0]);
        result.push_back((-poly[1] - determinant) / (2 * poly[2]));
        result.push_back((-poly[1] + determinant) / (2 * poly[2]));
        return result;
    }

    vector<double> differentiate(const vector<double>& poly) {
        vector<double> result(poly.size() - 1);
        for (int i = 1; i < poly.size(); ++i) {
            result[i - 1] = i * poly[i];
        }
        return result;
    }

    double evaluate(const vector<double>& poly, double x) {
        double result = poly[0];
        double k = 1;
        for (int i = 1; i < poly.size(); ++i) {
            k *= x;
            result += poly[i] * k;
        }
        return result;
    }

    vector<double> search() {
        return search(coefficient);
    }

    vector<double> search(vector<double>& coefficient) {
        if (coefficient.size() <= 3) return solveNaive(coefficient);
        vector<double> differentiated = differentiate(coefficient);
        vector<double> candidate = search(differentiated);
        candidate.insert(candidate.begin(), -10);
        candidate.push_back(10);

        vector<double> result;
        double x1, y1;
        double x2, y2;
        double mx, my;
        
        for (int i = 1; i < candidate.size(); ++i) {
            x1 = candidate[i - 1];
            y1 = evaluate(coefficient, x1);
            x2 = candidate[i];
            y2 = evaluate(coefficient, x2);
            if (y1 * y2 > 0) {
                continue;
            } else {
                if (y1 > y2) {
                    std::swap(x1, x2);
                    std::swap(y1, y2);
                }
                for (int iter = 0; iter < 100; ++iter) {
                    mx = (x1 + x2) / 2;
                    my = evaluate(coefficient, mx);
                    if (y1 * my > 0) {
                        x1 = mx;
                        y1 = my;
                    } else {
                        x2 = mx;
                        y2 = my;
                    }
                }
                result.push_back((x1 + x2) / 2);
            }
        }
        std::sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<double> coefficient(n + 1);
        for (int i = 0; i <= n; ++i) {
            cin >> coefficient[n - i];
        }
        Solution s(n, coefficient);
        vector<double> result = s.search();
        cout << setprecision(12) << std::fixed;
        for (auto x : result) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}