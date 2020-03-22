// https://cses.fi/problemset/task/1094/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    long long temp, result;
    result = 0;
    cin >> n;
    vector<long long> numList;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        numList.push_back(temp);
    }

    for (int i = 1; i < n; ++i) {
        if (numList[i] < numList[i - 1]) {
            result += numList[i - 1] - numList[i];
            numList[i] = numList[i - 1];
        }
    }
    cout << result << endl;
}