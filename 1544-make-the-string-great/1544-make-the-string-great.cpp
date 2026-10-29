class Solution {
public:
bool isSame(char c1, char c2) {
    if(c1==toupper(c1) && c2==toupper(c2)) {
        return false;
    }
    else if(c1==toupper(c2) || c2==toupper(c1)) {
        return true;
    }
    else {
        return false;
    }
}
    string makeGood(string s) {
        string ans="";
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(st.empty()) {
                st.push(s[i]);
            }
            else {
                if(isSame(st.top(),s[i])) {
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};