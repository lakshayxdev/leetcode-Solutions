class Solution {
public:
int max_area=0;
void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>> &visited, int &area) {
    int rows=grid.size();
    int cols=grid[0].size();
    if(r<0 || r>=rows) {
        return;
    }
    if(c<0 || c>=cols) {
        return;
    }
    if(grid[r][c]==0) {
        return;
    }
    if(visited[r][c]) {
        return;
    }
    visited[r][c]=true;
    if(grid[r][c]==1) {
        area++;
        max_area=max(max_area,area);
    }
    dfs(grid,r-1,c,visited,area);
    dfs(grid,r+1,c,visited,area);
    dfs(grid,r,c-1,visited,area);
    dfs(grid,r,c+1,visited,area);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    count++;
                    int area=0;
                    dfs(grid,i,j,visited,area);
                }
            }
        }
        return max_area;
    }
};