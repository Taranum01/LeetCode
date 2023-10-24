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

    vector<int> res;
    
    void DFS(TreeNode* root, int depth) {

        if(!root)
            return;
        
        if(depth == res.size()) {
            res.push_back(root->val);
        } 
        else {
            res[depth] = max(res[depth], root->val);
        }
        
        DFS(root->left, depth+1);
        DFS(root->right, depth+1);
    }
    
    vector<int> largestValues(TreeNode* root) {

        DFS(root, 0);
        return res;
    }
};