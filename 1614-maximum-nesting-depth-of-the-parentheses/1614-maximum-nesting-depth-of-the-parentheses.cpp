class Solution {
public:
    int maxDepth(string s) {
        string ans="";
        for(int i=0; i<s.size(); i++) {
            if(s[i]==')' || s[i]=='(') {
                ans+=s[i];
            }
            else {
                continue;
            }
        }
        stack<char> st;
        int maxi=INT_MIN;
        for(int i=0; i<ans.size(); i++) {
            if(ans[i]=='(') {
                st.push(ans[i]);
                maxi=max(maxi,(int)st.size());
            }
            else {
                st.pop();
            }
        }
        if(maxi==INT_MIN) {
            return 0;
        }
        return maxi;
    }
};