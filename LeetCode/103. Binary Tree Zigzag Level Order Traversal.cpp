// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
public:
    // 4 ms
    // 12.5 MB
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        
        while (!q.empty()) {
            int currLevelSize = q.size();
            vector<int> currLevel;
            
            while (currLevelSize--) {
                auto curr = q.front();
                q.pop();
                currLevel.push_back(curr -> val);
                if (curr -> left) q.push(curr -> left);
                if (curr -> right) q.push(curr -> right);
            }
            
            if (level % 2 == 0) {
                result.push_back(vector<int>(currLevel.rbegin(), currLevel.rend()));
            } else {
                result.push_back(currLevel);
            }
            ++level;
        }
        
        return result;
    }
};