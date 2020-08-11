// https://leetcode.com/problems/path-sum-ii/
// 8 ms
// 19.7 MB

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> cart;
        search(root, 0, sum, cart, result);
        return result;
    }
    
    void search(TreeNode* root, int curr, int target, vector<int>& cart, vector<vector<int>>& result) {
        if (root == nullptr) return;
        
        curr += root -> val;
        cart.push_back(root -> val);
        if (root -> left == nullptr && root -> right == nullptr) {
            if (curr == target)
                result.push_back(cart);
            cart.pop_back();
            return;
        }
        search(root -> left, curr, target, cart, result);
        search(root -> right, curr, target, cart, result);
        cart.pop_back();
        return;
    }
};