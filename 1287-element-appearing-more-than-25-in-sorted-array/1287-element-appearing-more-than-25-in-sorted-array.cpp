class Solution {
public:
    
    int findSpecialInteger(vector<int>& arr) {
        
		unordered_map<int, int> mp;
        
		for(int i=0; i<arr.size(); i++){
			mp[arr[i]]++;
		}
		for(auto a : mp){
            
			if(a.second>arr.size() / 4) {
                
				return a.first;
			}
		}
		return arr[0];
    }
};

