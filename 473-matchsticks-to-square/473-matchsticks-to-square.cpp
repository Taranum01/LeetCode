class Solution {
public:

    vector<int> sides = {0, 0, 0, 0};
    
    bool func(vector<int>& matchsticks, int pos, int n, int target)
    {
        if(pos == n)
        {
            return true;
        }
    
        for(int i = 0; i < 4; i++)
        {
      
            if(sides[i] + matchsticks[pos] <= target)
            {
                sides[i] += matchsticks[pos];
                
                if(func(matchsticks, pos + 1, n, target))
                    return true;
                
                sides[i] -= matchsticks[pos];
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        
        int n = matchsticks.size();
  
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += matchsticks[i];
        }

        if(sum % 4)
            return false;

        int target = sum / 4;
    
        sort(matchsticks.begin(), matchsticks.end(), greater<int> ());
       
        return func(matchsticks, 0, n, target);
    }
};