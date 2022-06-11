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
             vector <string> ans;
             void helper(string s, TreeNode* node) {
             s += to_string(node->val);
    
             if(node->left == NULL && node->right == NULL)
             ans.push_back(s);

             if(node->left)
             helper(s + "->", node->left);

             if(node->right) 
             helper( s + "->", node->right);
             }
    
public:
             vector<string> binaryTreePaths(TreeNode* root) {
             helper("", root);
             return ans;
    }
};