class Solution {
public:

    void solve(int curr, int n, vector<int>& res) {

        if(curr > n)
            return;
        
        res.push_back(curr);

        for(int nextDigit = 0; nextDigit <= 9; nextDigit++) {

            int nextnum = curr*10 + nextDigit;
            
            if(nextnum > n)
                return;
            
            solve(nextnum, n, res);
        }
    }

    vector<int> lexicalOrder(int n) {

        vector<int> res;
        
        for(int num = 1; num <= 9; num++)
            solve(num, n, res);
        
        return res;
    }
};