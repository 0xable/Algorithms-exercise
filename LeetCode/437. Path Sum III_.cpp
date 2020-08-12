// https://leetcode.com/problems/path-sum-iii/
// 24 ms
// 20.8 MB

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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> table;
        table[0] = 1;
        return search(root, 0, sum, table);
    }
    
    int search(TreeNode* root, int curr, int target, unordered_map<int, int>& table) {
        if (root == nullptr) return 0;
        
        curr += root -> val;
        int result = table[curr - target];
        
        table[curr] += 1;
        result += search(root -> left, curr, target, table);
        result += search(root -> right, curr, target, table);
        table[curr] -= 1;
        return result;
    }
};