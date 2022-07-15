#define m 1000000007
class Solution {
public:
    
    int sumSubarrayMins(vector<int>& A) {
        int N = A.size();
        vector <int> pre_smaller(N),next_smaller(N); 
        
        for(int i=0;i<N;i++)
        {
            pre_smaller[i]=i+1; // when there is no previous element which is less than A[i]
            next_smaller[i]=N-i; // when there is no next element which is less than A[i]
        }
        stack <int> p, n; 
        
        for(int i=0;i<N;i++)
        {
            while(!p.empty() && A[p.top()]>A[i])
                p.pop();
            if(!p.empty())
                pre_smaller[i]=i-p.top();
            p.push(i);
            while(!n.empty() && A[n.top()]>A[i])
            {   
                
                next_smaller[n.top()]=i-n.top();
                n.pop();
            }
            n.push(i);
        }
        int ans=0;
        for(int i=0;i<N;i++)
        {
            ans= (ans%m + (long)A[i]*(long)next_smaller[i]*(long)pre_smaller[i] %m) %m;
        }
        return ans;
    }
};