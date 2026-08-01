class Solution {
public:
int count=0;
void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &isSafe, vector<vector<bool>> &visited) {
    int rows=grid.size();
    int cols=grid[0].size();
    if(i<0 || i>=rows) {
        return;
    }
    if(j<0 || j>=cols) {
        return;
    }
    if(visited[i][j]) {
        return;
    }
    if(grid[i][j]==0)
    return;
    isSafe[i][j]=true;
    visited[i][j]=true;
    dfs(grid,i-1,j,isSafe,visited);
    dfs(grid,i+1,j,isSafe,visited);
    dfs(grid,i,j-1,isSafe,visited);
    dfs(grid,i,j+1,isSafe,visited);
}
    int numEnclaves(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>> isSafe(rows, vector<bool>(cols,false));
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        for(int j = 0; j < cols; j++) {
            if(grid[0][j] == 1)
                dfs(grid, 0, j, isSafe, visited);
        }

        for(int i = 1; i < rows; i++) {
            if(grid[i][cols-1] == 1)
                dfs(grid, i, cols-1, isSafe, visited);
        }
        for(int j = cols-2; j >= 0; j--) {
            if(grid[rows-1][j] == 1)
                dfs(grid, rows-1, j, isSafe, visited);
        }
        for(int i = rows-2; i > 0; i--) {
            if(grid[i][0] == 1)
                dfs(grid, i, 0, isSafe, visited);
        }

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 1 && !isSafe[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};