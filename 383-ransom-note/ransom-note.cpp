class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int>a(26);
        
        for(int i=0; i<(int)magazine.size();i++)
        {
            a[magazine[i]-'a']++;
        }
        for(int i=0; i<(int)ransomNote.size();i++)
            if (a[ransomNote[i]-'a']> 0)
            {
               a[ransomNote[i]-'a']--;
            }
            else 
            {
               return false;
            }
        return true;
}
            };
