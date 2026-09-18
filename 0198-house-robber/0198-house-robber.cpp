class Solution {
public:
int solve(vector<int> &nums, int n, vector<int> &dp) {
    if(n>=nums.size()) {
        return 0;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    int inc=solve(nums,n+2,dp)+nums[n];
    int exc=solve(nums,n+1,dp)+0;
    dp[n]=max(inc,exc);
    return dp[n];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,dp);
    }
};