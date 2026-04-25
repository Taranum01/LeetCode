class Solution {
public:
   vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
	{

		int n=nums1.size();
		int m=nums2.size();
       
		vector<int> res;
		unordered_map <int,int> mp; 

		for(int i=0;i<n;i++)
		{
			mp[nums1[i]]++; 
		}

		for(int j=0;j<m;j++)
		{
			if(mp.find(nums2[j])!=mp.end()) 
                
			{
				res.push_back(nums2[j]);

				mp.erase(nums2[j]); 
			}
		}

		return res;
	}
};
