class StockSpanner {
    
    stack<pair<int,int>>st;
    int i;
     
public:
    StockSpanner() {
       i=-1; 
    }
    
    int next(int price) {
        i+=1;
        while(!st.empty() && st.top().second<=price)
            st.pop();
        if(st.empty()){
            st.push({i,price});
            return i+1;
        }
        
        int res=st.top().first;
        st.push({i,price});
        return i-res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */