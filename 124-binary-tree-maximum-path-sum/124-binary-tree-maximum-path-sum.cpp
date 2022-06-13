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
    int maxPathSum(TreeNode* root) {
        
        if(root== NULL) return 0;
        int maxx= INT_MIN;
        maxPath(root, maxx);
        return maxx;
        
    }
        
    int maxPath(TreeNode* node, int &maxx){
        if(node==NULL) return 0;
        int left= max(0,maxPath(node->left,maxx));
        int right= max(0, maxPath(node->right, maxx));
        maxx= max(maxx, left+right+node->val);
            return max(left,right)+node->val;
    }
    
    
};