// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// 0 ms
// 12.4 MB

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
    int sumNumbers(TreeNode* root) {
        return search(root, 0);
    }
    
    int search(TreeNode* root, int curr) {
        if (root == nullptr) return 0;
        
        curr *= 10;
        curr += root -> val;
        if (root -> left == nullptr && root -> right == nullptr) {    
            return curr;
        }
        return search(root -> left, curr) + search(root -> right, curr);
    }
};