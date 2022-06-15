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
   
        vector<vector<int>>ans;
        void solve (TreeNode* root, vector<int>&path, int targetSum, int currSum){
            if(!root)
                return ;
            currSum+=root->val;
            path.push_back(root->val);
            if(currSum== targetSum and !root->left and !root->right)
            {
                ans.push_back(path);
            }
            solve(root->left,path, targetSum, currSum);
            solve(root->right, path, targetSum, currSum);
            path.pop_back();
        }
     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<int> path;
         solve(root, path, targetSum, 0);
         return ans;
    }
};