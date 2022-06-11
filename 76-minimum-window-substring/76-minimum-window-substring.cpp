class Solution {
public:
    string minWindow(string s, string t) {
    int len1 = s.length(); 
    int len2 = t.length(); 
  
    if (len1 < len2) 
        return "";
  
    int hash_t[256] = {0}; 
    int hash_s[256] = {0}; 
  
    for (int i = 0; i < len2; i++) 
        hash_t[t[i]]++; 
  
    int start = 0, start_index = -1, min_len = INT_MAX; 
  
   
    int count = 0; 
    for (int j = 0; j < len1 ; j++) 
    { 
        hash_s[s[j]]++;
        if (hash_t[s[j]] != 0 && 
            hash_s[s[j]] <= hash_t[s[j]] )
            count++; 
  
        if (count == len2) 
        { 
            while (hash_s[s[start]] > hash_t[s[start]] 
                || hash_t[s[start]] == 0) 
            { 
  
                if (hash_s[s[start]] > hash_t[s[start]]) 
                    hash_s[s[start]]--; 
                start++; 
            } 
  
          
            int len_window = j - start + 1; 
            if (min_len > len_window) 
            { 
                min_len = len_window; 
                start_index = start; 
            } 
        } 
    } 
  
    if (start_index == -1) 
    {
    return ""; 
    } 
 
    return s.substr(start_index, min_len); 

    }
};