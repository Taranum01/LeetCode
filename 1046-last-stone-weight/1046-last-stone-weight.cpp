class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> maxheap;
        int n= stones.size();
        
        for(int i=0; i<n; i++)
            maxheap.push(stones[i]);
            
            int first,second;
            
          while(n>1){
              
              first=maxheap.top();
              maxheap.pop();
              second=maxheap.top();
              maxheap.pop();
                  n-=2;
              
              if(first-second>0){
                  maxheap.push(first-second);
                  n+=1;
              }
          }
            
            if(!maxheap.empty())
                return maxheap.top();
            return 0;
        }
    
};