class Solution {
public:
bool isValid(int r, int c, vector<vector<int>>& grid, vector<vector<bool>> &visited) {
    int rows=grid.size();
    int cols=grid.size();
    if(r<0 || r>=rows) {
        return false;
    }
    else if(c<0 || c>=cols) {
        return false;
    }
    else if (grid[r][c] ==1) {
        return false;
    }
    else if(visited[r][c]) {
        return false;
    }
    else {
        return true;
    }
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] != 0) {
            return -1;
        }
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        q.push({0,0});
        visited[0][0]=true;
        distance[0][0]=1;
        int count=1;
        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty()) {
            auto it= q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            for(int i=0; i<8; i++) {
                int nr=r+dr[i];
                int nc=c+dc[i];

                 if(isValid(nr,nc,grid,visited)) {
                q.push({nr,nc});
                visited[nr][nc]=true;
                distance[nr][nc]=distance[r][c]+1;
            }
            }
           
        }
        if(distance[n-1][n-1] == INT_MAX) {
            return -1;
        }
        else {
            return distance[n-1][n-1];
        }
    }
};