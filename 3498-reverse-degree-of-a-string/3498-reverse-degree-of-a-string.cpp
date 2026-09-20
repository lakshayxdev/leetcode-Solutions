class Solution {
public:
    int reverseDegree(string s) {
       unordered_map<char,int> mp;
       char ch='a';
       int i=26;
       while(i>=1) {
        mp[ch]=i;
        ch++;
        i--;
       }

       int ans=0;
       for(int i=0; i<s.size(); i++) {
        int degree=(i+1)*mp[s[i]];
        ans+=degree;
       }
        return ans;
    }
};