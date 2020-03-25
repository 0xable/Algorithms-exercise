// https://algospot.com/judge/problem/read/DARPA

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool isAcceptable(int n, const vector<double>& pos, double step) {
    int numCamera = 1;
    auto it = pos.begin();
    double prev = *it;
    it++;
    while (it != pos.end()) {
        if (*it - prev >= step) {
            ++numCamera;
            prev = *it;
        }
        it++;
    }
    return numCamera >= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<double> position(m);
        for (int i = 0; i < m; ++i) {
            cin >> position[i];
        }
        double result = 0;
        double step = 240;
        while (step >= 0.001) {
            while (isAcceptable(n, position, result + step)) {
                result += step;
            }
            step /= 2;
        }
        cout << std::fixed << setprecision(2);
        cout << result << endl;
    }
    return 0;
}