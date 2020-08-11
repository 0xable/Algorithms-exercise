// https://leetcode.com/problems/path-sum/
// 12 ms
// 21.6 MB

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
    bool hasPathSum(TreeNode* root, int sum) {
        return search(root, 0, sum);
    }
    
    bool search(TreeNode* root, int curr, int target) {
        if (root == nullptr) return false;
        
        curr += root -> val;
        if (root -> left == nullptr && root -> right == nullptr)
            return curr == target;
        return search(root -> left, curr, target) || search(root -> right, curr, target);
    }
};