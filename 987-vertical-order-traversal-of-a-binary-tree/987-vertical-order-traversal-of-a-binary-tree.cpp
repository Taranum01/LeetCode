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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int, multiset<int>>>mp;
        queue<pair<TreeNode*, pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto a= q.front();
            q.pop();
            TreeNode *node= a.first;
            int x=a.second.first, y=a.second.second;
            mp[x][y].insert(node->val);
            if(node->left) {
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right) {
                q.push({node->right,{x+1, y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto a: mp){
            vector<int>v;
            for(auto b: a.second){
                v.insert(v.end(), b.second.begin(), b.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};