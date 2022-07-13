class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      
        vector<pair<long,long>>v(nums.size());
        t=(long)t;
        
        for(int i=0; i<nums.size(); i++){
            v[i].first= nums[i];
            v[i].second=i;
        }
        
        sort(v.begin(), v.end());
        
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if((long)v[i].first+t>= (long)v[j].first)
                {
                    if(abs((long)v[i].second -(long)v[j].second)<=k)
                    {
                        return true;
                    }
                }
                else {
                    break;
                }
            }
        }
         return false;
    }
};
