class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {

        vector<vector<int>> mem;
        int n = cells.size();
        vector<int> temp(n);
        
        while(N--)
        {
            for(int i=1;i<n-1;++i)
                temp[i] = cells[i-1]==cells[i+1]?1:0;
            
            if(mem.size()>0 && mem.front()==temp)
                return mem[N % mem.size()]; 
            else
                mem.push_back(temp);
   
            cells = temp;
        }
        return temp;
    }
};