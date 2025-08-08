class Solution {
public:

    vector<pair<int, int>> serves{{100, 0}, {75, 25}, {50, 50}, {25, 75}};

    vector<vector<double>> dp;
    
    double solve(double A, double B) {

        if(A <= 0 && B <= 0)
            return 0.5;
        
        if(A <= 0)
            return 1.0;
        if(B <= 0)
            return 0.0;
        
        if(dp[A][B] != -1.0)
            return dp[A][B];
        
        double probability = 0.0;
        
        for(auto &p : serves) {
            
            double A_serve  = p.first;
            double B_serve  = p.second;
            
            probability += 0.25*solve(A-A_serve, B-B_serve);
            
        }
        
        return dp[A][B] = probability;
    }
    
    double soupServings(int n) {
        
        if(n >= 5000)
            return 1.0;
        
        dp.resize(n+1, vector<double>(n+1, -1.0));
        return solve(n, n);
    }
};