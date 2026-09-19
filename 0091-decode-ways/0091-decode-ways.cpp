class Solution {
public:
int solve(string s, int i, int n, vector<int> &dp) {
    if(i==n) {
        return 1;
    }
    if(s[i]=='0') {
        return 0;
    }
    if(dp[i]!=-1) {
        return dp[i];
    }
     dp[i]=solve(s,i+1,n,dp);
    if(i+1<n) {
        int number=(s[i]-'0')*10+(s[i+1]-'0');
        if(number<=26 && number>=10) {
            dp[i]+=solve(s,i+2,n,dp);
        }
    }
    return dp[i];
}
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return solve(s,0,n,dp);
    }
};