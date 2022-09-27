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
     unordered_map<TreeNode*, int>dp;
public:
    int rob(TreeNode* root) {
       
        if(!root) return 0;
        if(dp[root]) return dp[root];
        
        int a1= rob(root->left)+rob(root->right);
        int a2= root->val;
        
        if(root->left)
        {
            a2+=rob(root->left->left)+ rob(root->left->right);
        }   
        if(root->right)
        {
            a2+=rob(root->right->left)+ rob(root->right->right);
        }   
        return dp[root]=max(a1,a2);
    }
};