class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n=colors.size();
        int i=0, j=0;
        int minTime=0;
        
        while(i<n && j<n){
            int maxTime=0, currTime=0;
            while(j<n && colors[i]==colors[j])
            {
                maxTime= max(maxTime, neededTime[j]);
                currTime+=neededTime[j];
                j++;
            }
            i=j;
            minTime+=(currTime-maxTime);
        }
        return minTime;
    }
};