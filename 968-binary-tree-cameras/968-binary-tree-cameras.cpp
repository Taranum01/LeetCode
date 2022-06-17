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
    
   // NOT_NEEDED = -1, NO_CAMERA = 0, HAS_CAMERA = 1;
    
    int cam = 0;
    
    int count_cam(TreeNode* root)
    {
        if(!root)
            return -1;
        
        int left = count_cam(root->left);
        int right = count_cam(root->right);
        
        if(left==0 || right==0){
            cam++;
            return 1;
        }
        else if(left==1 || right==1){
            return -1;
        }
        else{
            return 0;
        }
    }
    int minCameraCover(TreeNode* root)
    {
        if(count_cam(root)==0)
            cam++;
        return cam;
    }
};