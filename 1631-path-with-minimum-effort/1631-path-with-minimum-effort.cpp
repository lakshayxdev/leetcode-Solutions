class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
> pq;
int rows=heights.size();
int cols=heights[0].size();
vector<vector<int>> dist(rows, vector<int> (cols, 1e9));
pq.push({0,{0,0}});
dist[0][0]=0;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
while(!pq.empty()) {
    auto it=pq.top();
    pq.pop();
    int diff=it.first;
    int r=it.second.first;
    int c=it.second.second;
    for(int i=0; i<4; i++) {
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(nr>=0 && nr<rows && nc>=0 && nc<cols) {
            int effort=max(abs(heights[r][c]-heights[nr][nc]), diff);
            if(effort<dist[nr][nc]) {
                dist[nr][nc]=effort;
                pq.push({effort,{nr,nc}});
            }
        }
    }
}
return dist[rows-1][cols-1];
    }
};