class Solution {
public:
    
       vector<int> nextGreaterElements(vector<int> &nums){
           
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
           
        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && st.top() <= nums[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
           
        for (int i = n-1; i >= 0; i--){
            if(ans[i] == -1){
                while (!st.empty() && st.top() <= nums[i])
                st.pop();

                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i]);
        }

    return ans;
    }
};    