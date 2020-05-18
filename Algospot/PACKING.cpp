// https://algospot.com/judge/problem/read/PACKING

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, w;
        cin >> n >> w;

        vector<vector<int>> table(n, vector<int>(w + 1, 0));
        map<int, string> nameTable;
        vector<int> value(n);
        vector<int> volume(n);
        string name;
        for (int i = 0; i < n; ++i) {
            cin >> name >> volume[i] >> value[i];
            nameTable[i] = name;
        }
        for (int j = 0; j <= w; ++j) {
            if (j >= volume[0]) table[0][j] = value[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= w; ++j) {
                if (volume[i] <= j) {
                    table[i][j] = std::max(table[i - 1][j], table[i - 1][j - volume[i]] + value[i]);
                } else {
                    table[i][j] = table[i - 1][j];
                }
                
            }
        }

        int i = n - 1;
        int j = w;
        int result = table[n - 1][w];
        int count = 0;
        vector<int> itemList;

        while (i > 0) {
            if (table[i][j] != table[i - 1][j]) {
                itemList.push_back(i);
                ++count;
                while (table[i][j] == table[i][j - 1]) {
                    j--;
                }
                j -= volume[i];
            }
            i--;
        }
        if (table[i][j] != 0) {
            ++count;
            itemList.push_back(i);
        }
        cout << result << " " << count << endl;
        for (auto item : itemList) {
            cout << nameTable[item] << endl;
        }
    }
    return 0;
}