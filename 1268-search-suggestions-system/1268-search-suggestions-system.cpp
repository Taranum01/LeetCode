class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        int n=products.size();
        
        sort(products.begin(),products.end());
        
        vector<vector<string>>res;
        
        vector<string>temp;
        
        string curr="";
        
        for(auto c:searchWord)
        {
            curr+=c;             // like -> m-->mo-->mou-->mous--->mouse
            
            temp.clear();         
            
            for(int i=0;i<n;i++){
                
                string s=products[i];
                
                if(s.substr(0,curr.length())==curr){  //find prefix containing words in list
                    temp.push_back(s);
                }
                if(temp.size()==3)break;        
            }
            res.push_back(temp);
        }
        return res;
    }
};