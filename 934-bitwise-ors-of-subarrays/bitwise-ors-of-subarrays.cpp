class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {

        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> res;

        for(int i = 0; i < arr.size(); i++) {

            for(auto& x : prev) {
                curr.insert(x | arr[i]);
                res.insert(x | arr[i]);
            }

            curr.insert(arr[i]);
            res.insert(arr[i]);

            prev = curr;
            curr.clear();
        }

        return res.size();
    }
};