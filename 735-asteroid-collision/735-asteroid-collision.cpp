class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int>s;
        int n=asteroids.size();
        
        for (int ele: asteroids){
            
            if(ele>0 || s.empty() || s.top()<0 ){
                s.push(ele);
            }
            
            else {
                while(!s.empty() && s.top()>0 && s.top()< abs(ele))
                    s.pop();
                
                if(s.empty() || s.top()<0)
                    s.push(ele);
                else if(s.top()== abs(ele))
                    s.pop();
            }
        }
        
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

