class Solution {
public:
void solve(int n, int k, vector<int> &ans, vector<vector<int>> &final_ans,int start) {
    if(ans.size()==k) {
        final_ans.push_back(ans);
        return;
    }
    for(int i=start; i<=n; i++) {
        ans.push_back(i);
        solve(n,k,ans,final_ans,i+1);
        ans.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        vector<vector<int>> final_ans;
        solve(n,k,ans,final_ans,1);
        return final_ans;
    }
};