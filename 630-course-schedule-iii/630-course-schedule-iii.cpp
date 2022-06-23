class Solution {
public:
    
    struct compare{
        bool operator () (const vector <int>&i, const vector <int>&j){
            return i[1]<j[1];
        }
    };
    
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        if(courses.size() <= 0) 
            return 0;
        sort(courses.begin(), courses.end(), compare());
        
        priority_queue<int> q;
        int sum = 0;
        for(auto i : courses) {
            sum += i[0];
            q.push(i[0]);
            if(sum > i[1]) {
                sum -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};