class Solution {
public:
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = profit.size();
        using t = tuple<int,int,int>;
        vector<t> jobs;
        
        for(int i = 0; i<n;i++){
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        
        map<int,int>maxProfit = {{0,0}};
        
        int lastTime = 0;
        
        for(int i = 0;i <n; i++){
            auto [end,start,p] = jobs[i];
            int currProfit = (--maxProfit.upper_bound(start))->second+p;
            
            if(currProfit>maxProfit[lastTime]){
                maxProfit[end] = currProfit;
                lastTime = end;
            }
        }
        return maxProfit[lastTime];
        
    }
};