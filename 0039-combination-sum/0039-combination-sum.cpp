class Solution {
public:
void solve(vector<int> &candidates, int target, vector<int> &ans, vector<vector<int>> &final_ans, int start) {
    if(target==0) {
        final_ans.push_back(ans);
        return;
    }
    if(target<0) {
        return;
    }
    for(int i=start; i<candidates.size(); i++) {
        ans.push_back(candidates[i]);
        solve(candidates,target-candidates[i],ans,final_ans,i);
        ans.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> final_ans;
        solve(candidates,target,ans,final_ans,0);
        return final_ans;
    }
};