class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0; i<operations.size(); i++) {
            if(operations[i]=="C") {
                st.pop();
            }
            else if(operations[i]=="D") {
                int val=st.top();
                st.push(2*val);
            }
            else if(operations[i]=="+") {
                int val1=st.top();
                st.pop();
                int val2=st.top();
                int sum=val1+val2;
                st.push(val1);
                st.push(sum);
            }
            else {
                st.push(stoi(operations[i]));
            }
        }
        int ans=0;
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};