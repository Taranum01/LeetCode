class MinStack {
    stack<long long> s; 
    long long min; 
public:
   
    MinStack() {
        while(s.empty() == false) s.pop(); 
        min = INT_MAX; 
    }
    
        

void push(long val) {
    
        if(s.empty()){
        s.push(val);
        min = val;
    }
    else
    {
        if(val<min){
        s.push((long)2*val-min);
        min=val;
        }
        else
        s.push(val);
    }
}

void pop() {
    
    if(s.empty())
          return ;
          long curr=s.top();
          s.pop();
          if(curr>min){
          return ;
          }

    else{
          long val=(long)(2*min-curr);
          min=val;
          return ;
          }
}

int top() {
    
    if(s.empty())
        return -1;
    long curr=s.top();
    if(curr<min){
        return min;
    }
    else
        return curr;
}

int getMin() {
    if(s.empty())
        return -1;
    else
        return min;
}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */