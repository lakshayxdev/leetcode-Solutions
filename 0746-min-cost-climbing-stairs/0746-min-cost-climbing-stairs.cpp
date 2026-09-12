class Solution {
public:
int solve(int i, vector<int> &dp, vector<int>& cost) {
    if(i==0 || i==1) {
        return 0;
    } 
    if(dp[i] != -1) {
        return dp[i];
    }
    dp[i]= min(solve(i-1,dp,cost)+cost[i-1],solve(i-2,dp,cost)+cost[i-2]);
    return dp[i];
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return solve(n,dp,cost);
    }
};