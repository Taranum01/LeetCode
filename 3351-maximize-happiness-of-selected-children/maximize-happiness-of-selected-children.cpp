class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        long long res = 0;
        
        int count = 0;
        
        priority_queue<int> pq;
        
        for(int &h : happiness) {
            pq.push(h);
        }
        
        for(int i = 0; i < k; i++) {
            
            int h = pq.top();
            pq.pop();
            
            res += max(h - count, 0);
            
            count++;
            
        }
        
        return res;
    }
};