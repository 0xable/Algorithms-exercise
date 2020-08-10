// https://leetcode.com/problems/path-sum-iii/
// 64 ms
// 16.4 MB

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
        vector<int> sums;
        return search(root, sums, sum);
    }
    
    int search(TreeNode* root, vector<int>& sums, int sum) {
        if (root == nullptr) return 0;
        
        int val = root -> val;
        int result = 0;
        for (int i = 0; i < sums.size(); ++i) {
            sums[i] += val;
            if (sums[i] == sum) ++result;
        }
        sums.push_back(val);
        if (val == sum) ++result;
        
        result += search(root -> left, sums, sum);
        result += search(root -> right, sums, sum);
        sums.pop_back();
        for (int i = 0; i < sums.size(); ++i) {
            sums[i] -= val;
        }
        return result;
    }
};