class Solution {
public:
    int furthestBuilding(vector<int>& v, int b, int l) {
        
        int i=0;
        priority_queue<int>q;
        for(i;i<v.size()-1;i++){
            if(v[i+1]<=v[i]) continue;
            int d= v[i+1]-v[i];
            if(d<=b){
                b-=d;
                q.push(d);
            }
            else if(l>0){
                if(q.size()){
                    int x=q.top();
                if(x>d){
                    b+=x;
                    q.pop();
                    q.push(d);
                    b-=d;
                }
                }
                
                l--;
            }
            else break;
        }
        return i;
    }
};