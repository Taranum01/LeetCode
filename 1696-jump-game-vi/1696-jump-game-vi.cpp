class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        deque<int>dq;
        int n=nums.size();
        for(int i=0; i<n; i++){
            
            int maximum= dq.empty()?0: dq.front();
            nums[i]+=maximum;
            
            while(!dq.empty() and dq.back()<nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
            
            if(i>=k){
                if(!dq.empty() && dq.front()==nums[i-k])
                    dq.pop_front();
            }
                
        }
        
        return nums.back();
            
    }
};