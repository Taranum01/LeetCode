class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        int n1 = list1.size();
        int n2 = list2.size();
        
        int mini = INT_MAX;
        
        unordered_map<int, vector<string>> mp;
        
        for(int i = 0; i < n1; i++)
        {
            for(int j = 0; j < n2; j++)
            {
                if(list1[i] == list2[j])
                {
                    mini = min(mini, i + j);
                    mp[i + j].push_back(list1[i]);
                }
            }
        }
        return mp[mini];
    }
};
