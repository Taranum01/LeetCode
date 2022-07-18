class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        
        pq.push(amount[0]);
        pq.push(amount[1]);
        pq.push(amount[2]);
        
        int ans=0;
        
        while(pq.top()!=0){
            int p=pq.top();
            pq.pop();
            int q=pq.top();
            pq.pop();
            p--;
            q--;
            pq.push(p);
            pq.push(q);
            ans++;
            
        }
        return ans;
    }
};