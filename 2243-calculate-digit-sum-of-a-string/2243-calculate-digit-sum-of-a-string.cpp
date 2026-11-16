class Solution {
public:
    string digitSum(string s, int k) {
        string ans1="";
        int ans2=0;
        while(s.size()>k) {
           int j=0;
           for(int i=0; i<s.size(); i+=k) {
            int sum=0;
            for(int x=i; x<min(i+k,(int)s.size()); x++) {
                sum+=s[x]-'0';
            }
            string temp=to_string(sum);
            for(char c:temp) {
                s[j++]=c;
            }
           }
           s.resize(j);
        }
        return s;
    }
};