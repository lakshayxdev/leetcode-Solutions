class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> modify;
        for(int i=0; i<nums.size(); i++) {
            modify.push_back(nums[i]);
        }
        for(int i=0; i<nums.size(); i++) {
            modify.push_back(nums[i]);
        }
        stack<int> st;
        vector<int> ans(nums.size(),-1);
        for(int i=0; i<modify.size(); i++) {
            while(!st.empty() && modify[i] > modify[st.top()]) {
                ans[st.top()%nums.size()]=modify[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};