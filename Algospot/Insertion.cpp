// https://algospot.com/judge/problem/read/INSERTION

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
public:
    int priority;
    int key;
    int size;
    Node* left;
    Node* right;

    Node(int key) : key{key}, priority{std::rand()}, size{1} {
        left = right = nullptr;
    }
    void setLeft(Node* left) {
        this -> left = left;
        calcSize();
    }
    void setRight(Node* right) {
        this -> right = right;
        calcSize();
    }

    int calcSize() {
        size = 1;
        if (left != nullptr) size += left -> size;
        if (right != nullptr) size += right -> size;
        return size;
    }
    Node* kth(Node* root, int k) {
        if (root == nullptr) return nullptr;
        int size = 0;
        if (root -> left != nullptr) {
            size += root -> left -> size;
        }

        if (size >= k) {
            return kth(root -> left, k);
        } else if (size + 1 == k) {
            return root;
        } else {
            return kth(root -> right, k - size - 1);
        }
    }

    Node* insert(Node* root, Node* node) {
        if (root == nullptr) {
            root = node;
            return root;
        }

        if (root -> priority < node -> priority) {
            auto splitted = split(root, node -> key);
            node -> setLeft(splitted.first);
            node -> setRight(splitted.second);
            return node;
        }
        if (node -> key < root -> key) {
            root -> setLeft(insert(root -> left, node));
        } else {
            root -> setRight(insert(root -> right, node));
        }
        return root;
    }

    pair<Node*, Node*> split(Node* root, int key) {
        if (root == nullptr) return make_pair(nullptr, nullptr);
        if (root -> key < key) {
            auto splitted = split(root -> right, key);
            root -> setRight(splitted.first);
            return make_pair(root, splitted.second);
        }
        auto splitted = split(root -> left, key);
        root -> setLeft(splitted.second);
        return make_pair(splitted.first, root);
    }

    Node* merge(Node* left, Node* right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        if (left -> priority < right -> priority) {
            right -> setLeft(merge(left, right -> left));
            return right;
        } else {
            left -> setRight(merge(left -> right, right));
            return left;
        }
    }

    Node* erase(Node* root, int key) {
        if (root == nullptr) return root;
        if (root -> key == key) {
            Node* ret = merge(root -> left, root -> right);
            delete root;
            return ret;
        }
        if (key < root -> key) {
            root -> setLeft(erase(root -> left, key));
        } else {
            root -> setRight(erase(root -> right, key));
        }
        return root;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    std::srand(std::time(nullptr));

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Node* root = new Node(1);
        for (int i = 2; i <= n; ++i) {
            root = root -> insert(root, new Node(i));
        }

        vector<int> res(n);
        vector<int> input(n);
        for (int i = 0; i < n; ++i) {
            cin >> input[i];
        }
        for (auto it = input.rbegin(); it != input.rend(); ++it) {
            auto nth = root -> kth(root, (n - *it));
            n--;
            res[n] = nth -> key;
            root = root -> erase(root, nth -> key);
        }
        std::copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}