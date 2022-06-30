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
class Solution
{
public:
    struct s
    {
        bool isBST;
        int mini, maxi, sum;
    };

    
    s solve(TreeNode *root, int &res)
    {
        if (!root)
        {
            return {true, INT_MAX, INT_MIN, 0};
        }

        s left = solve(root->left, res);   
        s right = solve(root->right, res); 

        if (left.isBST && right.isBST && left.maxi < root->val && right.mini > root->val)
        {
            int cur = left.sum + right.sum + root->val; 
            res = max(res, cur);                       
            return {true, min(left.mini, root->val), max(right.maxi, root->val), cur};
        }
        else
            return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode *root)
    {
        int res = 0;
        solve(root, res);
        return res;
    }
};