class Solution {
public:
    
    int help(vector<int>&prices){
        int net_profit=0;
        for(int i=1; i<prices.size(); i++)
            if(prices[i]>prices[i-1])
                net_profit+=prices[i]-prices[i-1];
        return net_profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        if(k<=0 || prices.size()<=0) return 0;
        if(k>prices.size()/2){
            return help(prices);
        }
        int minp[k];
    int maxp[k];
    
    for(int i=0; i<k; i++){
        minp[i]=INT_MAX;
        maxp[i]=0;
    }
    
    for(int i=0; i<prices.size(); i++){
        for(int j=0; j<k; j++){
            minp[j]=min(minp[j],prices[i]-(j>0?maxp[j-1]:0));
            maxp[j]=max(maxp[j], prices[i]-minp[j]);
            }
         }
    
     return maxp[k-1];
        
    }
};
