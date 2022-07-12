class Solution {
public:
    
    string frequencySort(string str) {
        int n = str.size();
        unordered_map<char, int> mp;
        
        for(int i = 0; i < n; i++)
        {
            mp[str[i]]++;
        }
        
        priority_queue<pair<int, char>> pq;
    
        for(auto x : mp)
        {
            pq.push({x.second, x.first});
        }

        string ans = "";
        
        while(!pq.empty())
        {
            int freq = pq.top().first;   // count of curr char
            char ch = pq.top().second;    // curr char
            string curr(freq, ch);       // curr string
            ans += curr;                  
            pq.pop();  
        }
        
        return ans;
    }
};