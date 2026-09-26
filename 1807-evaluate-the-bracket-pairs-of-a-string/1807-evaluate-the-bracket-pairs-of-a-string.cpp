class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        string final_ans="";
        unordered_map<string,string> mp;
        for(int i=0; i<knowledge.size(); i++) {
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        int count=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(') {
                count++;
            }
            else if(s[i]==')') {
                count=0;
                string st="";
                if(mp.contains(ans)) {
                    st+=mp[ans];
                    final_ans+=st;
                }
                else {
                    final_ans+='?';
                } 
                ans="";
            }
            else {
                if(count==1) {
                    ans+=s[i];
                }
                else {
                    final_ans+=s[i];
                }
            }
        }
        return final_ans;
    }
};