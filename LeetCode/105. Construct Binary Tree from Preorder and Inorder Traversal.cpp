// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    // 28 ms
    // 23.4 MB
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        return build(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }
    
    TreeNode* build(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder) {
        if (preStart > preEnd) return nullptr;
        if (preStart == preEnd) return new TreeNode(preorder[preStart]);
        
        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);
        int rootIndex = inStart;
        while (rootIndex <= inEnd) {
            if (inorder[rootIndex] == rootValue) break;
            ++rootIndex;
        }
        
        int leftCount = rootIndex - inStart;
        root -> left = build(preStart + 1, preStart + leftCount, inStart, rootIndex - 1, preorder, inorder);
        root -> right = build(preStart + leftCount + 1, preEnd, rootIndex + 1, inEnd, preorder, inorder);
        return root;
    }
};