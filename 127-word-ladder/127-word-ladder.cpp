class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        bool lastPresent= false;
        
        for(auto w: wordList)
        {
            if(endWord.compare(w)==0)
                lastPresent= true;
            s.insert(w);
        }
        if(lastPresent==false)
            return 0;
        
        queue<string>q;
        q.push(beginWord);
        
        int depth=0;
        while(!q.empty())
        {
            depth+=1;
            int levelsize=q.size();
            while(levelsize--)
            {
                string curr=q.front();
                q.pop();
            
                for(int i=0; i<curr.length(); i++){
                    string temp= curr;
                
                for(char c='a'; c<='z'; c++){
                 temp[i]=c;
                 
                 if(curr.compare(temp)==0) continue;
                 if(temp.compare(endWord)==0) return depth+1;
                 if(s.find(temp)!=s.end()){
                     q.push(temp);
                     s.erase(temp);
                 }
              }   
            }
          } 
        }
        return 0;
    }
};