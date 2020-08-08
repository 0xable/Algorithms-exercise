// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// 0 ms
// 14.6 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> table;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        search(root, 0, 0);
        
        vector<vector<int>> result(table.size());
        int i = 0;
        for (auto& xAxis : table) {
            vector<int> curr;
            for (auto& yAxis : xAxis.second) {
                auto& pq = yAxis.second;
                while (!pq.empty()) {
                    curr.push_back(pq.top());
                    pq.pop();
                }
            }
            result[i] = curr;
            ++i;
        }
        return result;
    }
    
    void search(TreeNode* root, int x, int y) {
        if (root == nullptr) return;
        
        table[x][y].push(root -> val);
        search(root -> left, x - 1, y + 1);
        search(root -> right, x + 1, y + 1);
    }
};