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
    
    int findMax(vector<int>& nums, int start, int end)
    {
        int max_val = INT_MIN;
        int max_id = -1;
        
        for(int i=start; i <= end; i++)
        {
            if(nums[i] > max_val)
            {
                max_val = nums[i];
                max_id = i;
            }
        }
        
        return max_id;
    }
    
    TreeNode* helper(vector<int>& nums, int start, int end)
    {
        if(start>end)
        {
            return NULL;
        }
        
        int max_id = findMax(nums, start, end);
        int max_val = nums[max_id];
        
        TreeNode* root = new TreeNode(max_val);
        root -> left = helper(nums, start, max_id- 1);
        root -> right = helper(nums, max_id+ 1, end);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int n = nums.size();
        return helper(nums, 0, n-1);
    }
};