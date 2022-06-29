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
        int widthOfBinaryTree(TreeNode* root) {
        if (!root)
        return 0;
        int ans = 0;
        queue<pair<TreeNode*,int>>q;
          q.push({root,0});
            
          while (!q.empty()) {
            int size = q.size();
            int curr_min = q.front().second;
            int left, right;
            for (int i=0;i<size;i++) {
              long curr_id = q.front().second - curr_min; 
              TreeNode* temp = q.front().first;
              q.pop();
              if (i==0) left = curr_id;
              if (i==size - 1) right = curr_id;
              if (temp->left)
                q.push({temp->left, curr_id*2+1});
              if (temp -> right)
                q.push({temp->right, curr_id*2+2});
            }
            ans = max(ans, right- left+ 1);
          }
          return ans;
        }
        };