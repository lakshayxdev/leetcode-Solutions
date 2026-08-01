class Solution {
public:

void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>> &visited) {
    int rows=grid.size();
    int cols=grid[0].size();
    if(r<0 || r>=rows) {
        return;
    }
    if(c<0 || c>=cols) {
        return;
    }
    if(visited[r][c]) {
        return;
    }
    if(grid[r][c]=='0') {
        return;
    }
    visited[r][c]=true;

    dfs(grid, r-1, c, visited);
    dfs(grid, r+1, c, visited);
    dfs(grid, r, c-1, visited);
    dfs(grid, r, c+1, visited);

}
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int rows=grid.size();
        int count=0;
        int cols=grid[0].size();
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(grid[r][c] == '1' && !visited[r][c]) {
                    count++;
                    dfs(grid,r,c,visited);
                }
            }
        }
        return count;
    }
};
