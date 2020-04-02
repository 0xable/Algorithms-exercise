// https://algospot.com/judge/problem/read/FORTRESS

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

struct Node {
    int x, y, r;
    vector<Node> child;
    Node(int x, int y, int r) : x{x}, y{y}, r{r} {

    }
    Node() {

    }

    void set(int x, int y, int r) {
        this -> x = x;
        this -> y = y;
        this -> r = r;
    }

    void print(string s, Node& a) {
        cout << s << "(" << a.x << "," << a.y << "," << a.r << ")" << endl;
        for (auto& x : a.child) {
            print(s + "\t", x);
        }
    }
};

class Solution {
    Node root;
    int n;
    int maxHeight;
public:
    Solution(vector<tuple<int, int, int>>& castle, int n) : n{n} {
        maxHeight = 0;
        int x1, x2, y1, y2, r1, r2;
        tie(x1, y1, r1) = castle[0];
        root.set(x1, y1, r1);

        int distX, distY, dis;
        for (int i = 1; i < n; ++i) {
            tie(x2, y2, r2) = castle[i];
            bool flag = false;

            for (auto& node : root.child) {
                x1 = node.x;
                y1 = node.y;
                r1 = node.r;
                distX = x1 - x2;
                distY = y1 - y2;
                dis = distX * distX + distY * distY;
                if (dis < r1 * r1) {
                    insert(node, x2, y2, r2);
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                root.child.push_back(Node(x2, y2, r2));
            }
        }
        //root.print("", root);
        search(root);
    }

    void insert(Node& a, int x, int y, int r) {
        for (auto& node : a.child) {
            int distX = node.x - x;
            int distY = node.y - y;
            int dis = distX * distX + distY * distY;
            if (dis < node.r * node.r) {
                insert(node, x, y, r);
                return;
            }
        }
        a.child.push_back(Node(x, y, r));
    }

    int search(Node& a) {
        if (a.child.size() == 0) {
            return 1;
        }
        int first = 0, second = 0;
        for (auto& node : a.child) {
            int height = search(node);
            if (height > first) {
                second = first;
                first = height;
            } else if (height > second) {
                second = height;
            }
        }
        if (first + second > maxHeight) {
            maxHeight = first + second;
        }
        return first + 1;
    }

    int getAnswer() {
        return maxHeight;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, x, y, r;
        cin >> n;
        vector<tuple<int, int, int>> castle(n);
        for (int i = 0; i < n; ++i) {
            cin >> x >> y >> r;
            castle[i] = make_tuple(x, y, r);
        }
        std::sort(castle.begin(), castle.end(), [](tuple<int, int, int>& a, tuple<int, int, int>& b) -> bool {
            return get<2>(a) > get<2>(b);
        });
        Solution s(castle, n);
        cout << s.getAnswer() << endl;
    }
    return 0;
}