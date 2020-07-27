// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    // 8 ms
    // 23.2 MB
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return nullptr;
        return build(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder);
    }
    
    TreeNode* build(int inStart, int inEnd, int postStart, int postEnd, vector<int>& inorder, vector<int>& postorder) {
        if (inStart > inEnd) return nullptr;
        if (inStart == inEnd) return new TreeNode(inorder[inStart]);
        
        int rootValue = postorder[postEnd];
        TreeNode* root = new TreeNode(rootValue);
        int rootIdx = inEnd;
        while (rootIdx >= inStart) {
            if (inorder[rootIdx] == rootValue) break;
            --rootIdx;
        }
        
        int leftCount = rootIdx - inStart;
        root -> left = build(inStart, rootIdx - 1, postStart, postStart + leftCount - 1, inorder, postorder);
        root -> right = build(rootIdx + 1, inEnd, postStart + leftCount, postEnd - 1, inorder, postorder);
        return root;
    }
};