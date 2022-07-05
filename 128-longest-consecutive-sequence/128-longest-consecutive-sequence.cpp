// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         set<int>hashSet;
//         for(int num:nums)
//         {
//             hashSet.insert(num);
//         }
//         int longestSeq=0;
//         for(int num:nums){
//             if(!hashSet.count(num-1))
//             {
//                 int currNum= num;
//                 int currSeq= 1;
            
//             while(hashSet.count(currNum+1)){
//                 currNum+=1;
//                 currSeq+=1;
//             }
            
//             longestSeq= max(longestSeq, currSeq);
//         }
        
//     }
//     return longestSeq;
//     }
// };

#include<unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)!=s.end()){
                continue;
            
            }else{
                int longestSeq=0;
                int current=nums[i];
                while(s.find(current)!=s.end()){
                    longestSeq++;
                    current++;
                }
                
                ans=max(ans,longestSeq);
            } 
        }
        return ans;
        
    }
};

