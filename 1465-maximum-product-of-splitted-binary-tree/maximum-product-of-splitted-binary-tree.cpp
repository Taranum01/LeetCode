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
    long int MOD= 1e9+7;
    long totalsum=0;
    long ans=0;

    int help(TreeNode* root){

        if(!root) return 0;
        long subSum= help(root->left)+help(root->right)+root->val;
        ans= max(ans, (totalsum-subSum)*subSum);
        return subSum;
    }


    int maxProduct(TreeNode* root) {
        
        totalsum= help(root);
        help(root);
        return ans%MOD;
        
    }
};