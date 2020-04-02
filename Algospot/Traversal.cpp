// https://algospot.com/judge/problem/read/TRAVERSAL

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> result;
    int n;
public:
    Solution(const vector<int>& preOrder, const vector<int>& inOrder) : preOrder{preOrder}, inOrder{inOrder} {
        n = preOrder.size();
        search(preOrder, inOrder);
    }

    void search(const vector<int>& pOrder, const vector<int>& iOrder) {
        if (pOrder.empty()) return;
        if (pOrder.size() == 1) {
            result.push_back(pOrder[0]);
            return;
        }

        int root = pOrder[0];
        int i = 0;
        while (iOrder[i] != root) {
            ++i;
        }
        vector<int> pLeft(pOrder.begin() + 1, pOrder.begin() + i + 1);
        vector<int> pRight(pOrder.begin() + i + 1, pOrder.end());
        vector<int> iLeft(iOrder.begin(), iOrder.begin() + i);
        vector<int> iRight(iOrder.begin() + i + 1, iOrder.end());
        
        search(pLeft, iLeft);
        search(pRight, iRight);
        result.push_back(root);
    }

    void printAnswer() {
        ostream_iterator<int> oi(cout, " ");
        std::copy(result.begin(), result.end(), oi);
        cout << endl;
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
        vector<int> preOrder(n);
        vector<int> inOrder(n);
        for (int i = 0; i < n; ++i) {
            cin >> preOrder[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> inOrder[i];
        }
        Solution s(preOrder, inOrder);
        s.printAnswer();
    }
    return 0;
}