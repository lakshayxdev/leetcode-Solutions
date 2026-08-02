class Solution {
public:
int minutes=0;
int fresh=0;
bool isValid(vector<vector<int>>& grid,int r, int c) {
    int rows=grid.size();
    int cols=grid[0].size();
    if( (r<0 || r>=rows) || (c<0 || c>=cols) ) {
        return false;
    }
    return true;
}
void bfs(vector<vector<int>>& grid,
             vector<vector<bool>>& visited,
             queue<pair<int,int>>& q) {

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size(); 

            while (size--) {

                auto front = q.front();
                q.pop();

                int row = front.first;
                int col = front.second;

                for (int k = 0; k < 4; k++) {

                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (isValid(grid, nr, nc) &&
                        !visited[nr][nc] &&
                        grid[nr][nc] == 1) {

                        visited[nr][nc] = true;
                        grid[nr][nc] = 2;
                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }
            if (!q.empty())
                minutes++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int,int>> q;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    visited[i][j]=true;
                }
                else if(grid[i][j]==1) {
                    fresh++;
                }
            }
        }
        bfs(grid,visited,q);
        if(fresh==0) {
            return minutes;
        }
        else {
            return -1;
        }
    }
};