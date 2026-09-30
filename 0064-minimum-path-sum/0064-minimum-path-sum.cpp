class Solution {
public:

int solve(vector<vector<int>> &grid, int sr,int sc, vector<vector<int>> &dp, int rows, int cols) {
    if(sr>=rows || sc>=cols) {
        return 1e9;
    }
    if(sr==rows-1 && sc==cols-1) {
        return grid[sr][sc];
    }
    if(dp[sr][sc] != -1) {
        return dp[sr][sc];
    }
    dp[sr][sc]=grid[sr][sc]+min(solve(grid,sr+1,sc,dp,rows,cols),solve(grid,sr,sc+1,dp,rows,cols));
    return dp[sr][sc];
}
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        int sum=0;
        // int target=grid[rows-1][cols-1];
        return solve(grid,0,0,dp,rows,cols);
        
    }
};