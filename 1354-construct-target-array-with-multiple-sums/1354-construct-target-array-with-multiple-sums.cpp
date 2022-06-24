class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        
        priority_queue<int> pq;
        long long sum = 0;
        for(auto num : target){
            pq.push(num);
            sum+=num;
            
        }
        
        while(pq.top() != 1){
            sum -= pq.top();
            
            if(sum == 0 || sum >= pq.top()) 
             return false;
            int old_elem = pq.top()%sum;
            
            if(sum != 1 && old_elem == 0) 
                return false;
            pq.pop();
            pq.push(old_elem);
            sum += (old_elem);
        }
        return true;
    }
};