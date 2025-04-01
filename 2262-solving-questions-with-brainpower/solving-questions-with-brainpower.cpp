class Solution {
public:

    long long mostPoints(vector<vector<int>>& questions) {

        int n = questions.size();
        
        if(n == 1)
            return questions[0][0];
        
        vector<long long> dp(200001);
       
        for(int i = n-1; i >= 0; i--) {

            dp[i] = max(questions[i][0] + dp[i + questions[i][1] + 1], dp[i+1]);

        }
        
        return dp[0];
    }
};