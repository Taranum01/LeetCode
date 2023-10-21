class Solution {
public:
    typedef pair<int, int> P;

    int constrainedSubsetSum(vector<int>& nums, int k) {

        int n = nums.size();
        
        vector<int> v(n, 0);
        v = nums;

        priority_queue<P, vector<P>> pq;
        pq.push({v[0], 0});
        
        int maxR = v[0];
        
        for(int i = 1; i<n; i++) {
            
            while(!pq.empty() && pq.top().second < i - k)
                pq.pop();
            
            v[i] = max(v[i], nums[i] + pq.top().first);
            pq.push({v[i], i});
            
            maxR = max(maxR, v[i]);
        }
        
        
        return maxR;
    }
};