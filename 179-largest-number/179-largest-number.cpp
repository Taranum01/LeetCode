
bool comp(string s1,string s2)
{
    return s1+s2>s2+s1;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
         vector<string>res;
         for(int i=0;i<nums.size();i++)
             res.push_back(to_string(nums[i]));
         sort(res.begin(),res.end(),comp);
         string ans="";
         for(int i=0;i<res.size();i++)
             ans=ans+res[i];
        if(ans[0]=='0')
            return "0";
        return ans;
    }
};