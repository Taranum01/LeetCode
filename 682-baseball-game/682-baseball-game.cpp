class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        vector<int>score;
        int size=0;
        
        for(auto i:ops){
            
            if(i=="+"){
                score.push_back(score[size-1]+score[size-2]);
                size++;
            }
            else if (i=="D"){
                score.push_back(2*score[size-1]);
                size++;
            }
            else if(i=="C") {
            size--;
            score.pop_back();
            }
            
            else {
                size++;
                score.push_back(stoi(i));
            }
        }
        
        int sum=0;
        for(int i =0; i<size; i++) {
            sum+= score[i];
        }
        
        return sum;
    }
};