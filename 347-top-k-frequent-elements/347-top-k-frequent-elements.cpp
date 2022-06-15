class Solution {
public:
   vector<int> topKFrequent(vector<int>& nums, int k) {
		
		vector<int> v;
       
		unordered_map<int, int> mp;
		
		for(auto num: nums){
			mp[num]++;
		}
		
		priority_queue<pair<int,int>> heap;
       
		for(auto value: mp){
			heap.push({value.second, value.first});
		}
		
		while(k--){
			v.push_back(heap.top().second);
			heap.pop();
		}
		
		return v;
	}
	};