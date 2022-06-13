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
private:
      bool solve(TreeNode* root, long long minValue, long long maxValue)
      {
        if(!root) return true;
        
        if(root->val <= minValue || root->val >= maxValue) return false;
        
        return solve(root->left, minValue, root->val) && solve(root->right, root->val, maxValue);
    }

public:
        bool isValidBST(TreeNode* root) {
           return solve(root, LONG_MIN, LONG_MAX);
    }
};


