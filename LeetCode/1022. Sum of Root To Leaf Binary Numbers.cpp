// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// 4 ms
// 16.7 MB

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
    int sumRootToLeaf(TreeNode* root) {
        return search(root, 0);
    }
    
    int search(TreeNode* root, int curr) {
        if (root == nullptr) return 0;
        curr = curr * 2 + root -> val;
        if (root -> left == nullptr && root -> right == nullptr) return curr;
        return search(root -> left, curr) + search(root -> right, curr);
    }
};