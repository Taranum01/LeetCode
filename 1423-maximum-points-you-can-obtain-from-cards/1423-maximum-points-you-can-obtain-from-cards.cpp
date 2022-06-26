class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        
        vector<int>sum(cardPoints.size(),0);
        int TotalSum=0;
        for(int i=0; i<cardPoints.size(); i++) 
        {
            TotalSum+=cardPoints[i];
            sum[i]=TotalSum;
            
        }
        if(cardPoints.size()==k) return TotalSum;
        int max_score=0;
        int ans=0;
        for(int i=0; i<=k; i++){
            int j= i+cardPoints.size()-k-1;
            if(i==0) ans= sum[j];
            else ans= sum[j]-sum[i-1]; //sum of subarray we are going to remove
            max_score= max(max_score,TotalSum-ans);
        }
        
        return max_score;
    }
};