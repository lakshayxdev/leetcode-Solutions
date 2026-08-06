class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
> pq;
vector<vector<int>> Time(rows,vector<int> (cols,1e9));
Time[0][0]=grid[0][0];
pq.push({grid[0][0],{0,0}});
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
while(!pq.empty()) {
    auto it=pq.top();
    pq.pop();
    int time=it.first;
    int r=it.second.first;
    int c=it.second.second;
    if(r==rows-1 && c==cols-1) {
        return time;
    }
    for(int i=0; i<4; i++) {
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(nr>=0 && nr<rows && nc>=0 && nc<cols) {
            int time_taken=max(time,grid[nr][nc]);
            if(Time[nr][nc] > time_taken) {
                Time[nr][nc]=time_taken;
                pq.push({time_taken, {nr,nc}});
            }
            if(time>Time[nr][nc]) {
                continue;
            }
        }
    }
}
return -1;
    }
};