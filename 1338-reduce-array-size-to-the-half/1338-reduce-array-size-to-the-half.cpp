class Solution {
public:
    
	int minSetSize(vector<int>& arr) {
        
		unordered_map<int,int>mp;
		priority_queue<int>pq;
        
		for(auto i:arr){  
			mp[i]++;
		}
        
		for(auto i:mp){   
			pq.push(i.second);
		}
        
		int a=0, n=arr.size(), ans=0;
        
		while(a<n/2){    
			a+=pq.top();  
			pq.pop();      
			ans++;       
		}
		return ans;  
	}
};