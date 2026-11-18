class Solution {
public:
    string toLowerCase(string s) {
        string ans="";
        for(char ch:s) {
            if(ch>='A' && ch<='Z') {
                char newch='a'+(ch-'A');
                ans+=newch;
            }
            else {
                ans+=ch;
            }
        }
        return ans;
    }
};