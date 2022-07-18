class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        vector<int> ans;
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto &i :mp)
        {
            if(i.second==2)
                ans.push_back(i.first);
        }
        
        for(int i=1;i<=nums.size();i++)
         {
             if(mp[i]==0)
             {
                 ans.push_back(i);
             }
        }
        
        return ans;
    }
};
