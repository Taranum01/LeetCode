class Solution {
public:

    int getLastMoment(int n, vector<int>& left, vector<int>& right) {

        int res = 0;
        
        for(int &x : left) {
            res = max(x, res);
        }
        
        for(int &x : right) {
            res = max(res, n-x);
        }
        
        return res;
    }
};

