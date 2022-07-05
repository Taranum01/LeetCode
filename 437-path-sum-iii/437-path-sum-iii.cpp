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
    
    int pathSum2(TreeNode* root, int sum){
        if(root == NULL) return 0;
        int res = 0;
        if(root->val == sum) res++;
        res += pathSum2(root->left, (long long) sum-root->val);
        res += pathSum2(root->right, (long long) sum-root->val);
        return res;
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        return pathSum(root->left, sum) + pathSum2(root, sum) + pathSum(root->right, sum);
    }
};