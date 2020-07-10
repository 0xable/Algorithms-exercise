// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    vector<pair<int, int>> eachLevel;
public:
    // 24 ms
    // 15.7 MB
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int res = 0;
        
        while(!q.empty()) {
            int qs = q.size();
            int l = numeric_limits<int>::max();
            int r = numeric_limits<int>::min();
            int offset = q.front().second;
            while(qs--) {
                auto p = q.front();
                q.pop();
                l = min(l, p.second - offset);
                r = max(r, p.second - offset);
                if (p.first->left) q.push(make_pair(p.first -> left, 2 * (p.second - offset)));
                if (p.first->right) q.push(make_pair(p.first -> right, 2 * (p.second - offset) + 1));
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};