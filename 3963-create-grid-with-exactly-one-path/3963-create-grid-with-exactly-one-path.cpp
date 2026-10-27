class Solution {
public:
bool isValid(int i, int j, int m, int n) {
    if(i<0 || j<0 || i>=m || j>=n) return false;
    else return true;
}
vector<pair<int,int>> solve(vector<string> &ans, int m, int n, int i, int j, vector<pair<int,int>> &store) {
   while(i!=m-1 || j!=n-1) {
    if(isValid(i,j+1,m,n)) {
        store.push_back({i,j+1});
        j=j+1;
    }
    if(isValid(i+1,j,m,n)) {
        store.push_back({i+1,j});
        i=i+1;
    }
   }
    return store;
}
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m,string(n,'#'));
        vector<pair<int,int>> store;
        store.push_back({0,0});
        solve(ans,m,n,0,0,store);
        for(auto &p:store) {
            ans[p.first][p.second]='.';
        }
        return ans;
    }
};