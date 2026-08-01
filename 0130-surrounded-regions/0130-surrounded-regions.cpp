class Solution {
public:

void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>> &isSafe, vector<vector<bool>> &visited) {
    int rows=board.size();
    int cols=board[0].size();
    if(i<0 || i>=rows) {
        return;
    }
    if(j<0 || j>=cols) {
        return;
    }
    if(visited[i][j])
    return;
    if(board[i][j]=='X')
    return;

    visited[i][j]=true;
    isSafe[i][j] = true;
    dfs(board,i-1,j,isSafe,visited);
    dfs(board,i+1,j,isSafe,visited);
    dfs(board,i,j-1,isSafe,visited);
    dfs(board,i,j+1,isSafe,visited);
}

    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<bool>> isSafe(rows,vector<bool>(cols,false));
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
for(int j = 0; j < cols; j++) {
            if(board[0][j] == 'O')
                dfs(board, 0, j, isSafe, visited);
        }

        for(int i = 1; i < rows; i++) {
            if(board[i][cols-1] == 'O')
                dfs(board, i, cols-1, isSafe, visited);
        }
        for(int j = cols-2; j >= 0; j--) {
            if(board[rows-1][j] == 'O')
                dfs(board, rows-1, j, isSafe, visited);
        }
        for(int i = rows-2; i > 0; i--) {
            if(board[i][0] == 'O')
                dfs(board, i, 0, isSafe, visited);
        }

         for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'O' && !isSafe[i][j])
                    board[i][j] = 'X';

            }
        }
            
    }
};