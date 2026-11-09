class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<pair<int,int>> vec;
        int count=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j]==1) {
                    vec.push_back({i,j});
                }
            }
        }
        for(int i=0; i<vec.size(); i++) {
            bool communicate=false;
            for(int j=0; j<vec.size(); j++) {
                if(i==j) continue;
                if(vec[i].first==vec[j].first || vec[i].second==vec[j].second) {
                    communicate=true;
                    break;
                }
            }
            if(communicate==true) count++;
        }
        return count;
    }
};