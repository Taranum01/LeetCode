class Twitter 
{    
    vector<pair<int,int>> timeline;
    unordered_map<int,unordered_set<int>> following;
    
public:
    
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        
        timeline.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        int n = timeline.size();
        vector<int> ans;
        int count = 0;
        int i = n-1;
        while(count < 10 && i>= 0)
        {
            pair<int,int>p = timeline[i];
            if(p.first == userId || following[userId].count(p.first))
            {
                ans.push_back(p.second);
                count++;
            }
            i--;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */